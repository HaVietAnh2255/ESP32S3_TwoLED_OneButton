# Điều Khiển 2 Đèn LED Bằng 1 Nút Nhấn (OneButton) Trên ESP32-S3

Dự án mở rộng dựa trên thư viện **OneButton** kết hợp với thư viện hướng đối tượng `LED.h` tự viết, cho phép sử dụng duy nhất một nút bấm để chọn kênh và điều khiển độc lập hai đèn LED với các hiệu ứng khác nhau.

---

## 1. Yêu cầu bài toán

Hệ thống sử dụng một nút bấm đa năng để kiểm soát hai đèn LED (`LED 1` và `LED 2`):
- **Double Click (Nhấp đúp nhanh):** Chuyển đổi đối tượng LED đang được chọn (`LED 1` $\leftrightarrow$ `LED 2`).
- **Single Click (Nhấn 1 lần):** Đảo trạng thái Bật / Tắt (ON/OFF) của đèn LED đang được chọn.
- **Long Press (Nhấn và giữ nút):** Kích hoạt chế độ nhấp nháy liên tục (chu kỳ 200ms) cho đèn LED đang được chọn.
- Nhấn Single Click lại lần nữa sẽ dừng nháy và quay về trạng thái Bật/Tắt bình thường.
- Tự động khử rung phím bấm (Debounce) bằng phần mềm qua thư viện `OneButton`.

---

## 2. Sơ đồ kết nối phần cứng (ESP32-S3 DevKitC-1)

| Linh kiện | Chân trên ESP32-S3 | Chân còn lại | Ghi chú |
| :--- | :--- | :--- | :--- |
| **Nút bấm rời** | `GPIO 5` | `GND` | Cấu hình `INPUT_PULLUP` (Nhấn = mức `LOW`) |
| **LED 1 (ngoài)** | `GPIO 4` (qua trở 220Ω) | `GND` | Tích cực mức `HIGH` |
| **LED 2 (ngoài)** | `GPIO 6` (qua trở 220Ω) | `GND` | Tích cực mức `HIGH` |

> *Ghi chú:* Dự án sử dụng nút bấm gắn chân `GPIO 5` thay cho nút BOOT (`GPIO 0`) để loại bỏ hoàn toàn hiện tượng kẹt vào chế độ Bootloader khi nhấn phím liên tục.

---

## 3. Cấu trúc thư mục dự án

```text
├── include/
│   └── (các header file mở rộng nếu có)
├── lib/
│   └── LED/
│       └── LED.h            # Class điều khiển LED non-blocking
├── src/
│   └── main.cpp             # Logic máy trạng thái và gán sự kiện nút bấm
├── platformio.ini           # Cấu hình môi trường ESP32-S3 N16R8 và build_flags
└── README.md                # Tài liệu mô tả dự án