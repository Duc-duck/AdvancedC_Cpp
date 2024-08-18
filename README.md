# Lesson 1: Compiler-Macro

## Compiler ##

- Trình biên dịch là một chương trình máy tính được thiết kế để dịch code viết bằng một ngôn ngữ lập trình (source language) sang ngôn ngữ khác (the target language). 

- Compiler thường dùng biên dịch ngôn ngữ bậc cao (C++, Java,...) về ngôn ngữ bậc thấp hơn (ASM, object code,...) để tạo ra một chương trình mà máy tính có thể hiểu và thực thi được.


## Các bước biên dịch chương trình

![Compiler](images/Compiler.png)

### Bước 1: Preprocessing

Đầu tiên Compiler sẽ nhận source code, sau đó tiến hành các bước tiền xử lý: 
- **Include header**: Thay thế các dòng code bắt đầu bằng "#include" bằng toàn bộ nội dung đã code trong các file mà chương trình hiện tại (main) đang include.
- **Expand macro**: đọc nội dung macro đã được định nghĩa, mỗi khi macro được gọi thì tên macro được thay thế bằng nội dung của macro đó.
- **Xóa comment**: xóa toàn bộ các dòng comment được viết trong source code.
- **Tạo file .i/.ii**: sau khi thực hiện 3 bước trên, ta có nội dung code hoàn chỉnh của source code (main) được lưu dưới định dạng file .i (chỉ lưu ra một file duy nhất là file của chương trình chính).

Lệnh thực hiện trên terminal:
```c
gcc -E main.c -o main.i
```

### Bước 2: Preprocessing

Các file sau tiền xử lý (.i, .ii) được biên dịch thành các file assembly (.s). Bước này compiler sẽ vừa biên dịch vừa tìm lỗi.

### Bước 3: Assemble

Các file assembly được chuyển đổi thành các file mã máy (machine code hay object code) có định dạng .o(đối với c) hoặc .obj (đối với C++) bởi assembler.

### Bước 4: Linking

Cuối cùng linker sẽ kết hợp các file object code với các file thư viện (.lib, .a) để tạo thành một file chương trình có thể thực thi được (file .exe).
