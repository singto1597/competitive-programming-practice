# 🧰 tools/ — คู่มือสคริปต์

สรุปว่าแต่ละตัวทำอะไร ใช้ตอนไหน — เปิดไฟล์นี้เวลาลืม

repo นี้เป็น**โจทย์ฝึก** จึงไม่มีสคริปต์ที่ผูกกับ grader/คะแนน
(`sync_done` · `find_missed` · `folder_names` · `scorelib` · `graders.txt` · `scores/`
อยู่ที่ repo ค่าย ไม่ได้เอามาที่นี่)

---

## อยากทำอะไร → ใช้ตัวไหน

| อยาก... | รัน |
|---|---|
| **คอมไพล์ + รันโจทย์** (ใช้บ่อยสุด) | `python3 tools/run.py <รหัส>` |
| ติดตั้งคีย์ลัด `Ctrl+F5` = build + run | `python3 tools/vscode_keys.py --apply --only-this-repo` |
| จัด PDF ที่โหลดมือมาแบบลอย ๆ เข้าโฟลเดอร์ | `fish tools/organize.fish <โฟลเดอร์> --cpp` |

มี 3 ตัวเท่านั้น — `run.py` · `vscode_keys.py` · `organize.fish`

---

## `run.py` — คอมไพล์ + รันโจทย์

ตัวที่ใช้บ่อยที่สุด ทั้งจาก terminal และคีย์ลัดใน VS Code
**รู้จักโจทย์สองทรงเอง** จึงใช้คำสั่งเดียวกันได้หมด

| ทรง | หน้าตา | คอมไพล์ยังไง |
|---|---|---|
| ไฟล์เดียว | `<รหัส>.cpp` มี `main()` ในตัว | คอมไพล์ไฟล์นั้นไฟล์เดียว |
| **โจทย์ฟังก์ชัน** | `<โฟลเดอร์ grader>/grader.cpp` (มี `main`) + `<โฟลเดอร์ grader>/<รหัส>.h` เราเขียนแค่ตัวฟังก์ชัน | คอมไพล์ `-I <โฟลเดอร์ grader> <grader>.cpp <ไฟล์เรา>.cpp` |

โฟลเดอร์ของ grader ชื่ออะไรก็ได้ (`provided/` · `attachment/` · `provided_yrc/` · ชื่ออื่น)
สคริปต์ดูเนื้อในว่ามี `.h` หรือ `.cpp` ที่มี `main()` ไหม ไม่ได้ดูชื่อ
และจับคู่ "ไฟล์เรา ↔ โฟลเดอร์ grader" จาก `#include "…"` ในไฟล์เรา
ถ้ากำกวมมันจะหยุดแล้วบอก ไม่เดาต่อ — ใช้ `--list` ดูว่าเลือกอะไรเพราะอะไร

**หาโฟลเดอร์โจทย์จากรหัส** — ชื่อโฟลเดอร์ต้องเป็น `<รหัส>_<ชื่อโจทย์>`
(`1234A_Alice_and_Bob`) หรือ `<รหัส>` เปล่า ๆ · เทียบแบบไม่สนตัวพิมพ์

```fish
python3 tools/run.py 1234A                  # หาโฟลเดอร์จากรหัส แล้วคอมไพล์ + รัน
python3 tools/run.py --file <path>.cpp      # วิธีที่ tasks.json ใช้ (${file})
python3 tools/run.py --here                 # ใช้โฟลเดอร์โจทย์ที่ครอบ cwd อยู่
python3 tools/run.py 1234A -b               # คอมไพล์อย่างเดียว
python3 tools/run.py 1234A --sample 1       # รันด้วย sample ที่ 1 (+เทียบ .out ถ้ามี)
python3 tools/run.py 1234A --all-samples    # วนทุก sample สรุป "เทียบได้ N · ผ่าน M"
python3 tools/run.py 1234A --stdin in.txt --out res.txt
python3 tools/run.py 1234A -i               # พิมพ์ input เองจาก terminal
python3 tools/run.py 1234A --asan           # AddressSanitizer + UBSan (ล่าล้น/oob)
python3 tools/run.py 1234A --with local/brute.cpp   # คอมไพล์ไฟล์เพิ่ม
python3 tools/run.py 1234A -- 2 3           # ส่ง argument ที่เหลือให้โปรแกรม
python3 tools/run.py 1234A --list           # โชว์ layout/ไฟล์/sample แล้วจบ
python3 tools/run.py 1234A --clean          # ลบ .run/ ของข้อนี้
```

ของที่ออกมา
- **`input.in` / `output.txt` อยู่ที่ราก repo** — ไฟล์เดียวใช้ทุกข้อ ก็อปทับได้เลย
  เปิดแท็บค้างไว้ได้ และ **ไม่หายตอน `--clean`**
- `<โฟลเดอร์โจทย์>/.run/` เก็บแค่ `bin` กับ `<sample>.got` ตอนเทียบไม่ผ่าน
  (`launch.json` อ้าง `.run/bin` อยู่)

**ลำดับการหา input:** `--stdin` → `--sample` → `input.in` (ราก repo) → `.run/input.in`
(ที่อยู่เก่า) → sample แรก → ไม่มีเลย (สร้าง `input.in` เปล่าให้)

⚠️ สคริปต์พิมพ์ทุกครั้งว่าใช้ input ไฟล์ไหน — ไฟล์เดียวใช้ร่วมทุกข้อ
ถ้าเปลี่ยนข้อแล้วลืมเปลี่ยน input มันจะเงียบ ๆ ใช้ของเก่า

**รายละเอียดที่ช่วยชีวิต**
- `-std=` อ่านจาก `compile*.sh` ของโฟลเดอร์ grader ถ้ามี (ไม่ต้องจำ) · `--std c++20` ทับได้
- timeout 10 วิ กัน infinite loop (`--timeout` ปรับได้)
- error เป็นภาษาไทยที่บอกทางออก ไม่ปล่อย traceback
- ใช้ได้ทั้ง Linux (`bin`) และ Windows (`bin.exe`)

---

## `vscode_keys.py` — ติดตั้งคีย์ลัด Ctrl+F5

VS Code ไม่มี keybindings ระดับ workspace — สคริปต์เขียนลงไฟล์ของผู้ใช้ให้
(หาโฟลเดอร์เองทั้ง Linux / macOS / Windows รวม VSCodium / Cursor / Insiders / flatpak)

```fish
python3 tools/vscode_keys.py                          # ดูเฉย ๆ ว่าจะเขียนอะไร
python3 tools/vscode_keys.py --apply --only-this-repo  # เขียนจริง (แนะนำ)
python3 tools/vscode_keys.py --print                   # พิมพ์ JSON ให้ก็อปวางเอง
python3 tools/vscode_keys.py --apply --remove           # ถอนออก
```

- **`--only-this-repo`** จำกัดให้คีย์ลัดทำงานเฉพาะ repo นี้ — แนะนำถ้าเคยติดตั้ง
  คีย์ลัดของ repo ค่ายไว้แล้ว จะได้ไม่แย่ง `Ctrl+F5` กัน
- ไม่ทับของเดิม — แทรกเป็นสมาชิกตัวสุดท้าย มี marker `competitive-programming-practice`
  ล้อมไว้ รันซ้ำได้ไม่ซ้อน · `--remove` ถอนออกได้
- ⚠️ ต้องรันบนเครื่องที่เปิด VS Code · `args` อ้าง label `C++: build + run`
  ถ้าแก้ label ใน `tasks.json` คีย์ลัดจะพัง

| คีย์ | ทำอะไร |
|---|---|
| **`Ctrl+F5`** | build + run |
| `Ctrl+Shift+B` | build อย่างเดียว (ใช้ได้เลยไม่ต้องติดตั้ง) |

---

## `organize.fish` — จัด PDF ที่โหลดมือ

ไฟล์ที่โหลดมาชื่อมักรก เช่น `Two Sum (en).pdf` → สร้างโฟลเดอร์ `Two_Sum/`
แล้วย้ายเป็น `Two_Sum.pdf` (ตัดวงเล็บ แทนเว้นวรรคด้วย `_` เก็บชื่อไทยครบ)
ถ้ามีโฟลเดอร์ที่ขึ้นต้นด้วยชื่อนั้นอยู่แล้ว (`1234A_Alice_and_Bob`) จะย้ายเข้าไปในนาม
`1234A.pdf` แทนสร้างโฟลเดอร์ซ้ำ

```fish
fish tools/organize.fish ~/Downloads --dry-run   # ดูเฉย ๆ ยังไม่ย้าย
fish tools/organize.fish ~/Downloads --cpp       # ย้าย + สร้าง .cpp จาก template.cpp
fish tools/organize.fish ~/Downloads --prefix 20261026
```

**ทำทีละโฟลเดอร์** — จัดผิดที่ก็ย้ายกลับได้ ไฟล์ไม่หาย

⚠️ อย่าเก็บ PDF statement ของ Codeforces/TOI/POSN ไว้ใน repo นี้ — เก็บแค่ลิงก์
และสรุปของตัวเอง (ลิขสิทธิ์ไม่ใช่ของเรา)

---

## เจอปัญหา

| อาการ | สาเหตุ / ทางแก้ |
|---|---|
| `run.py` บอก "ไม่เจอโจทย์รหัส …" | ชื่อโฟลเดอร์ต้องเป็น `<รหัส>_<ชื่อโจทย์>` หรือ `<รหัส>` — หรือใช้ `--file <path>.cpp` |
| `run.py` บอก "ไม่มี main และไม่มี grader" | เขียน `main` ในไฟล์เรา หรือใช้ `--with "<ไฟล์ที่มี main>"` |
| `run.py` บอกว่าจับคู่ไฟล์กับ grader ไม่ได้ | ใช้ `--list` ดูว่าเจออะไร แล้วชี้ด้วย `--file "<ไฟล์ของเรา>"` |
| `run.py` รันแล้ว EOF | ยังไม่มี input — วางที่ `input.in` ราก repo หรือใช้ `--sample N` / `--stdin` / `-i` |
| `run.py` ใช้ input ผิดข้อ | `input.in` เป็นไฟล์เดียวใช้ร่วมทุกข้อ — เช็คบรรทัด `ℹ️ input:` |
| `run.py` รันค้างไม่จบ | ตัดจบเองที่ 10 วิ — ปรับด้วย `--timeout` |
| แก้ไฟล์ใน `provided/` ไม่ได้ | ตั้งใจ — เป็นของที่โจทย์ให้มา (read-only ใน `.vscode/settings.json`) |
| กด `Ctrl+F5` แล้วเงียบ | ยังไม่ได้ติดตั้งคีย์ลัด หรือ label task ถูกแก้ |
