# Concurrent Log Analyzer (Java)

این پروژه یک ابزار پردازش لاگ به‌صورت همزمان در زبان Java است که با تمرکز بر Concurrency در JVM و استفاده از Stream API پیاده‌سازی شده است.  
هدف اصلی پروژه نمایش پردازش موازی داده‌های متنی، طراحی thread-safe و تحلیل آماری لاگ‌ها بدون استفاده از فریم‌ورک‌های وب می‌باشد.

این سیستم لاگ‌ها را از چند فایل به‌صورت همزمان می‌خواند، داده‌ها را به‌صورت stream پردازش می‌کند و گزارش آماری قابل‌خواندن تولید می‌کند.

## Execution Model

این پروژه به‌صورت CLI اجرا می‌شود و به‌صورت طراحی‌شده فاقد Live URL است.  
اجرای آن به‌عنوان یک ابزار محلی در نظر گرفته شده و هدف آن نمایش تفکر JVM و پردازش همزمان داده‌ها می‌باشد، نه ارائه‌ی یک سرویس وب.

با این حال، خروجی اجرای پروژه در محیط Cloud (Render) در تصویر زیر قابل مشاهده است.

![Concurrent Log Analyzer Output](https://raw.githubusercontent.com/garryand182-cmyk/gig-one/main/docs/1.png)

## معرفی پروژه – امکانات

این سیستم قابلیت‌های زیر را دارد:

- پردازش همزمان فایل‌های لاگ با استفاده از ExecutorService  
- استفاده از Stream API برای filter، map و aggregation  
- طراحی thread-safe با استفاده از ConcurrentHashMap  
- استفاده از immutable data objects با record  
- مدیریت داده‌های نامعتبر با Optional  
- تولید گزارش آماری از خطاها (مانند Top Errors)  
- مناسب برای پروژه‌های JVM-centric و پردازش داده‌های متنی  

## تکنولوژی‌ها

- Java 17 یا بالاتر  
- Maven  
- java.util.concurrent  
- Stream API  

## پیش‌نیازها

- Java 17 یا بالاتر  
- Maven یا Maven Wrapper  
- سیستم‌عامل Windows، Linux یا macOS  

## نصب و اجرا

### بیلد پروژه
```bash
mvn clean package

یا با Maven Wrapper:

./mvnw clean package

اجرای برنامه
java -cp target/concurrent-log-analyzer-1.0.0.jar com.example.loganalyzer.Main <log-folder>


مثال:

java -cp target/concurrent-log-analyzer-1.0.0.jar com.example.loganalyzer.Main logs/
