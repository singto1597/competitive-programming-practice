# CP Practice — เวิร์กสเปซทำโจทย์ฝึก

ทำโจทย์ competitive programming เพื่อฝึกเอง — **ไม่มีการส่ง grader ไม่มีตารางคะแนน**
ต่างจาก `03_Academics/OCom_2026/Camp1/olympicComputer-camp1-2569` ที่เป็นงานค่าย

## แผนผัง

| โฟลเดอร์ | เก็บอะไร |
|---|---|
| `problems/<แหล่ง>/` | โจทย์ 1 ข้อ = 1 โฟลเดอร์ — `codeforces/` · `programming.in.th/` · `toi/` · `posn/` · `other/` |
| `notes/` | สรุปเทคนิค / cheatsheet ที่เขียนเอง |
| `tools/` | `run.py` · `vscode_keys.py` · `organize.fish` — ดู `tools/README.md` |
| `.vscode/` | `tasks.json` (build/run) · `launch.json` (F5) · `settings.json` |

## กติกาในโฟลเดอร์นี้

- โฟลเดอร์โจทย์ = **`<รหัส>_<ชื่อโจทย์>`** ใต้ `problems/<แหล่ง>/`
  เช่น `problems/codeforces/1234A_Alice_and_Bob/`
- ไฟล์ที่เขียนอยู่ **ชั้นบนสุดของโฟลเดอร์โจทย์** ชื่อ **`<รหัส>.cpp`**
  เวอร์ชันลอง/brute ใส่ `local/` · ของที่โจทย์ให้มา (ถ้ามี) ใส่ `provided/` หรือ
  `attachment/` และ **ห้ามแก้** (ตั้ง read-only ใน `.vscode/settings.json`)
- **ห้าม commit statement/PDF ของเว็บ** (Codeforces · TOI · POSN มีลิขสิทธิ์)
  เก็บแค่ลิงก์ + สรุปของตัวเองใน `<รหัส>.md`
- `input.in` / `output.txt` อยู่ **ราก repo** ไฟล์เดียวใช้ทุกข้อ (gitignore)
  `.run/` เก็บไบนารีที่คอมไพล์ออกมา (gitignore)
- **ห้ามลบ/ย้ายโฟลเดอร์โจทย์ที่ทำแล้วโดยไม่ถาม** — เป็นบันทึกการฝึกสะสม
- repo นี้เป็น git repo (GitHub: `singto1597/competitive-programming-practice`)
  — commit/push เมื่อผู้ใช้สั่งเท่านั้น · ห้าม commit `input.in` / `output.txt` / `.run/`
  (gitignore ไว้แล้ว) และห้าม commit statement ของเว็บ

## เวลาทำงานที่นี่

- ภาษา C++17 สไตล์ competitive: `bits/stdc++.h` ได้ เขียนสั้น เร็ว ไม่ต้อง OOP
- รันด้วย **`python3 tools/run.py <รหัส>`** — สคริปต์เดียวรู้จักโจทย์ไฟล์เดียวและ
  โจทย์แบบฟังก์ชัน (`provided/` + `.h`) · ใช้ `--sample`, `--all-samples`, `--asan`
  ดูธงทั้งหมดใน `tools/README.md`
- ใน VS Code: `Ctrl+F5` = build + run · `Ctrl+Shift+B` = build
- อัปเดตสถานะในตาราง `README.md` เมื่อทำข้อนั้นได้ (🟢 AC · 🟡 ยังไม่ AC · 🔴 ค้าง)
