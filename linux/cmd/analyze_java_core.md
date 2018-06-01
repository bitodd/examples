##### how to analyze java core file
1. generate java core by using create_core.sh
2. when got a core file
    - analyze memory heap:
        - jmap -dump:format=b,file=dump.hprof /usr/bin/java corefile
        - jhat -port 8080 -J-Xmx4G dump.hprof
        - input 127.0.0.1:8080 in web browser
    - get crash core stack
        - gdb java corefile
