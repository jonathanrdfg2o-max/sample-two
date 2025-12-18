Custom Memory Pool + Debug Tool (C)
==================================

✔ Render-ready (Background Worker)
✔ No external dependencies
✔ CLI-based debugging output
✔ Detects:
    - Memory leaks
    - Double free
    - Invalid free

--------------------
Render Deployment
--------------------
Service Type: Background Worker

Build Command:
    gcc main.c mempool.c -o mempool_demo

Start Command:
    ./mempool_demo

The program is expected to EXIT normally.
Logs are visible in Render dashboard.

--------------------
Local Build
--------------------
    gcc main.c mempool.c -o mempool_demo
    ./mempool_demo
