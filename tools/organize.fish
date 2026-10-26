#!/usr/bin/env fish
#
# จัด PDF โจทย์ที่โหลดมือมาแบบลอย ๆ ให้เข้าโฟลเดอร์ของตัวเอง
#
#   fish tools/organize.fish ~/Downloads
#   fish tools/organize.fish ~/Downloads --cpp      # สร้าง .cpp จาก template ด้วย
#   fish tools/organize.fish ~/Downloads --dry-run  # ดูเฉย ๆ ยังไม่ย้าย
#   fish tools/organize.fish ~/Downloads --prefix 20261026
#
# กติกา: "Two Sum (en).pdf" → โฟลเดอร์ "Two_Sum/Two_Sum.pdf"
#        ตัดวงเล็บทิ้ง แทนเว้นวรรคด้วย _ (ชื่อไทยเก็บไว้ครบ ไม่ตัดทิ้ง)
#        ถ้ามีโฟลเดอร์ที่ขึ้นต้นด้วยชื่อนั้นอยู่แล้ว (เช่น 1234A_Alice_and_Bob)
#        จะย้าย PDF เข้าไปในนาม 1234A.pdf แทนการสร้างโฟลเดอร์ซ้ำ

argparse 'cpp' 'dry-run' 'prefix=' 'h/help' -- $argv
or exit 1

set -l script_dir (realpath (dirname (status filename)))
set -l root (realpath $script_dir/..)

if set -q _flag_h; or test (count $argv) -eq 0
    echo 'จัด PDF ที่ลอยอยู่ในโฟลเดอร์ ให้เข้าโฟลเดอร์ของตัวเอง'
    echo
    echo '  fish tools/organize.fish <โฟลเดอร์> [--cpp] [--dry-run] [--prefix ชื่อ]'
    echo
    echo 'ตัวอย่าง:'
    echo '  fish tools/organize.fish ~/Downloads --cpp'
    exit 0
end

set -l target $argv[1]
if not string match -q '/*' -- $target
    set target $root/$target
end

if not test -d $target
    echo "❌ ไม่เจอโฟลเดอร์ $target"
    exit 1
end

set -l template $root/template.cpp
set -l prefix ''
if set -q _flag_prefix
    set prefix $_flag_prefix
end

echo "🚀 จัดระเบียบ PDF ใน $target"
echo "--------------------------------------------------"

set -l count 0
set -l skipped 0

for file in $target/*.pdf
    test -e "$file"; or continue

    set -l base (basename -s .pdf -- "$file")
    set -l clean (string replace -ra '\s*\([^)]*\)' '' -- $base)   # ตัด (th) (en) (C++) ทิ้ง
    set clean (string replace -ra '\s+' '_' -- $clean)             # เว้นวรรค → _
    set clean (string trim -- $clean)

    if test -n "$prefix"
        set clean "$prefix"_"$clean"
    end

    if test -z "$clean"
        echo "⚠️  ข้าม: ชื่อไฟล์กลายเป็นว่าง («$base»)"
        set skipped (math $skipped + 1)
        continue
    end

    # หาโฟลเดอร์ที่มีอยู่แล้วซึ่งขึ้นต้นด้วยชื่อนี้ (1234A_Alice_and_Bob)
    set -l found
    for cand in $target/*
        test -d "$cand"; or continue
        set -l cand_name (basename $cand)
        if test "$cand_name" = "$clean"; or string match -q -- "$clean"'_*' $cand_name
            set -a found $cand_name
        end
    end

    if test (count $found) -gt 1
        echo "⚠️  $clean — เจอหลายโฟลเดอร์: $found (ข้าม ไฟล์ $base.pdf ยังค้างอยู่)"
        set skipped (math $skipped + 1)
        continue
    end

    set -l folder $clean
    if test (count $found) -eq 1
        set folder $found[1]
    end
    set -l dir $target/$folder

    if set -q _flag_dry_run
        echo "👀 $base.pdf → $folder/$clean.pdf"
        set count (math $count + 1)
        continue
    end

    mkdir -p $dir
    mv -- "$file" $dir/$clean.pdf
    echo "✅ $folder — ย้าย PDF เข้าโฟลเดอร์แล้ว"

    if set -q _flag_cpp
        if not test -e $dir/$clean.cpp
            if test -f $template
                cp $template $dir/$clean.cpp
                echo "   📝 สร้าง $clean.cpp จาก template.cpp"
            else
                touch $dir/$clean.cpp
                echo "   ⚠️  สร้าง $clean.cpp เปล่า ๆ (ไม่เจอ template.cpp)"
            end
        end
    end

    set count (math $count + 1)
end

echo "--------------------------------------------------"
if set -q _flag_dry_run
    echo "👀 จะย้าย $count ไฟล์ · ข้าม $skipped (โหมด --dry-run ยังไม่แตะอะไร)"
else
    echo "🎉 ย้าย $count ไฟล์ · ข้าม $skipped"
end
