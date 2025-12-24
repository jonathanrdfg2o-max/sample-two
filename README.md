# Custom Memory Pool & Debugger (C + Render)

این پروژه یک Custom Memory Pool سطح پایین در زبان C است که همراه با یک ابزار داخلی برای Debugging حافظه پیاده‌سازی شده است. تمرکز اصلی پروژه روی کنترل دستی حافظه، بهینه‌سازی Performance و تشخیص خطاهای رایج حافظه بدون استفاده از ابزارهای خارجی می‌باشد.

این سیستم امکان تخصیص و آزادسازی سریع حافظه را فراهم کرده و به‌صورت خودکار Memory Leak و Double Free را تشخیص می‌دهد.

این پروژه به‌صورت CLI اجرا می‌شود و Live URL ندارد. خروجی اجرای واقعی آن در محیط Cloud (Render) در تصویر زیر قابل مشاهده است.

Memory Pool Debug Output

![Memory Pool Debug Output](https://github.com/jonathanrdfg2o-max/sample-two/blob/main/docs/render-log-demo.png)

این پروژه به‌صورت CLI اجرا می‌شود و به‌صورت طراحی‌شده فاقد Live URL است.

---

## معرفی پروژه – امکانات

این سیستم قابلیت‌های زیر را دارد:

- پیاده‌سازی Custom Memory Pool بدون وابستگی خارجی
- تخصیص سریع حافظه از Pool ثابت
- تشخیص Double Free در زمان اجرا
- تشخیص Memory Leak در پایان برنامه
- گزارش خوانا از وضعیت حافظه
- مناسب برای System Programming و پروژه‌های Performance-sensitive

---

## پیش‌نیازها

- GCC یا C Compiler سازگار
- Linux / macOS / Windows

---

## نصب و اجرا

کامپایل:
```bash
gcc main.c mempool.c -o mempool_demo
