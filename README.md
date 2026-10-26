# 🏋️ CP Practice — คลังโจทย์ฝึก

เวิร์กสเปซส่วนตัวสำหรับ**ทำโจทย์ฝึก** (ไม่ได้ส่ง grader · ไม่มีตารางคะแนน)
โครงเดียวกับ `olympicComputer-camp1-2569` แต่ตัดทุกอย่างที่ผูกกับ CMU/YRC grader ออก

> GitHub: <https://github.com/singto1597/competitive-programming-practice>
>
> งานค่าย (มี grader + คะแนน) → `03_Academics/OCom_2026/Camp1/olympicComputer-camp1-2569`
> งานแต่งโจทย์ → repo `cp-problem-setting` (ยังไม่สร้าง)
> ที่นี่ตอบคำถามเดียว: **"ข้อนี้เราทำผ่านหรือยัง และเขียนยังไง"**

---

## 📁 โครงสร้าง

```
practice/
├── README.md            ← ไฟล์นี้ (สารบัญโจทย์ที่ทำ)
├── CLAUDE.md            ← บริบทให้ AI ช่วยงาน
├── template.cpp         ← โค้ดตั้งต้นของทุกข้อ
├── input.in             ← input ที่ใช้ซ้อม (ไฟล์เดียวใช้ทุกข้อ · gitignore)
├── output.txt           ← stdout ครั้งล่าสุด (gitignore)
├── .vscode/             ← tasks.json (build/run) · launch.json (F5) · settings.json
│
├── problems/            ← 1 โจทย์ = 1 โฟลเดอร์
│   ├── codeforces/
│   ├── programming.in.th/
│   ├── toi/
│   ├── posn/
│   └── other/             AtCoder · Kattis · ฯลฯ
│
├── notes/               ← สรุปเทคนิค / cheatsheet ที่เขียนเอง
└── tools/               ← run.py · vscode_keys.py · organize.fish — ดู tools/README.md
```

### โฟลเดอร์โจทย์ 1 ข้อ

```
problems/codeforces/1234A_Alice_and_Bob/
├── 1234A.cpp          ← โค้ดที่เขียน (ชื่อไฟล์ = รหัสโจทย์)
├── 1234A.md           ← ลิงก์ + สรุปโจทย์/ไอเดียของเรา (ไม่ก็อป statement)
├── sample/            ← sample ที่โจทย์ให้มา (ไม่บังคับ)
│   ├── 1.in
│   └── 1.out
├── local/             ← เวอร์ชันลอง / brute ของเรา (ไม่บังคับ)
└── .run/              ← ไบนารีที่คอมไพล์ออกมา (gitignore)
```

---

## กติกา

- **1 โจทย์ = 1 โฟลเดอร์** ใต้ `problems/<แหล่ง>/` ชื่อ `<รหัส>_<ชื่อโจทย์>`
  เช่น `1234A_Alice_and_Bob` · `0001_Grading` · `toi0_beehive`
- **ไฟล์โค้ดชื่อ `<รหัส>.cpp`** (ไม่ต่อชื่อโจทย์) — เรียก `run.py` ด้วยรหัสได้ตรง ๆ
  ถ้าอยากลองเวอร์ชันอื่นให้ใส่ `local/` เช่น `local/1234A_brute.cpp`
- **ห้าม commit statement ของเว็บ** — Codeforces / TOI / POSN มีลิขสิทธิ์
  เก็บแค่ลิงก์ + สรุปของตัวเองใน `<รหัส>.md` (หรือ `notes/`)
- **`input.in` / `output.txt` อยู่ราก repo** ไฟล์เดียวใช้ทุกข้อ — ก็อปทับได้เลย
  ไม่หายตอน `run.py --clean` และไม่ต้องลากไฟล์ใหม่
- ไฟล์ที่คอมไพล์/รันออกมาอยู่ **`.run/`** ของโฟลเดอร์โจทย์ (gitignore)
- โจทย์แบบฟังก์ชัน (ถ้าเจอ) — ของที่โจทย์ให้มาอยู่ใน `provided/` หรือ `attachment/`
  **ห้ามแก้** (ตั้ง read-only ใน `.vscode/settings.json`) ไฟล์ที่เราแก้อยู่ชั้นบนสุด

### สถานะในตาราง

| สถานะ | ความหมาย |
|:---:|---|
| 🟢 | AC แล้ว (หรือทำได้เองโดยไม่ดูเฉลย) |
| 🟡 | ทำได้แต่ยังไม่ AC / เปิดเฉลยอ่านแล้วเข้าใจ |
| 🔴 | ยังไม่ผ่าน / ยังค้างอยู่ |

---

## 🚀 เริ่มทำข้อใหม่

1. สร้างโฟลเดอร์ `problems/<แหล่ง>/<รหัส>_<ชื่อโจทย์>/`
2. `cp template.cpp problems/<แหล่ง>/<รหัส>_<ชื่อโจทย์>/<รหัส>.cpp`
3. เขียนลิงก์ + สรุปสั้น ๆ ไว้ใน `<รหัส>.md` (ถ้ามี sample ให้วางใน `sample/`)
4. ก็อป input ใส่ `input.in` ที่ราก repo แล้วรัน
   ```
   python3 tools/run.py <รหัส>
   ```
5. เพิ่มแถวใน[ตารางด้านล่าง](#-ตารางโจทย์) — อัปเดตสถานะเมื่อทำได้

ใน VS Code: เปิดไฟล์ `.cpp` แล้วกด **`Ctrl+F5`** (build + run) หรือ **`Ctrl+Shift+B`** (build)
ครั้งแรกต้องติดตั้งคีย์ลัดก่อน — `python3 tools/vscode_keys.py --apply --only-this-repo`

---

## 🧾 คำสั่งที่ใช้บ่อย

```fish
python3 tools/run.py 1234A                 # คอมไพล์ + รัน
python3 tools/run.py 1234A -b              # คอมไพล์อย่างเดียว
python3 tools/run.py 1234A --sample 1      # รัน sample ที่ 1 (เทียบ .out ให้)
python3 tools/run.py 1234A --all-samples   # วนทุก sample แล้วสรุป
python3 tools/run.py 1234A -i              # พิมพ์ input เองจาก terminal
python3 tools/run.py 1234A --asan          # AddressSanitizer + UBSan
python3 tools/run.py 1234A --list          # โชว์ว่าเลือกไฟล์/grader/sample อะไร
python3 tools/run.py 1234A --clean         # ลบ .run/ ของข้อนี้
```

ที่มาของ input: `--stdin` → `--sample N` → `input.in` (ราก repo) → sample แรก
สคริปต์พิมพ์ทุกครั้งว่าใช้ไฟล์ไหน เพราะไฟล์เดียวใช้ร่วมทุกข้อ

---

## 📋 ตารางโจทย์

<!-- เพิ่มแถวใหม่บนสุด · ลิงก์โฟลเดอร์ใช้ path สัมพัทธ์จากราก repo -->

| สถานะ | แหล่ง | โจทย์ | เทคนิค | วันที่ | โฟลเดอร์ |
|:---:|---|---|---|---|---|
<!-- | 🟢 | Codeforces | 1234A — Alice and Bob | greedy, sort | 2026-10-26 | [📁](problems/codeforces/1234A_Alice_and_Bob) | -->

---

## 🧰 tools

| อยาก... | รัน |
|---|---|
| คอมไพล์ + รันโจทย์ (ใช้บ่อยสุด) | `python3 tools/run.py <รหัส>` |
| ติดตั้ง `Ctrl+F5` ใน VS Code | `python3 tools/vscode_keys.py --apply --only-this-repo` |
| จัด PDF ที่โหลดมือเข้าโฟลเดอร์ | `fish tools/organize.fish <โฟลเดอร์> --cpp` |

รายละเอียดทุกธง: [tools/README.md](tools/README.md)
