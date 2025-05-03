# magang-KRSTI-2025

Program yang disusun untuk tugas magang ini memanfaatkan library mpu6050_tockn untuk berkomunikasi dengan komponen mpu6050. Library mpu6050_tockn menyediakan prosedur kalibrasi dan fungsi kalkulasi sudut. Untuk mengawasi perhitungan orientasi sudut, digunakan serial monitor yang meng-output nilai sudut setiap saat. 

Ketika arduino nano disambungkan dengan power supply, arduino nano akan melakukan kalibrasi mpu6050 selama sekitar 3 detik, lalu 3 detik setelahnya, mpu6050 akan mulai mengirimkan data dari accelerometer dan gyroscope ke arduino yang akan diolah menggunakan library. Pada prosedur setup(), sudut pitch dan roll awal setelah kalibrasi akan dianggap sebagai titik acuan sehingga orientasi sudut pada prosedur loop() diinisialisasi sebagai perubahan sudut dari titik acuan. Tiap loop, akan diperiksa apakah sudut pitch/roll melebihi 90 derajat. Jika iya, LED akan masuk ke mode blink dan akan dihitung interval waktu yang diperlukan untuk 1 kedipan dengan menghitung nilai mutlak sudut terbesar (maks 180) dan persamaan linear (sudut 90 derajat menghasilkan 500 ms, sudut 180 derajat menghasilkan 150 ms). Selanjutnya, jika setelah interval waktu tersebut LED masih dalam mode blink, sinyal digital yang berkebalikan (nyala ke mati, mati ke nyala) akan dikirimkan ke LED sehingga LED berkedip.


Anggota Kelompok:
1. Ahmad Zaky Robbani (Penyusun program)
2. Anggita Shabrina Lumembang Arso
3. Alfatihah Nurmahmudi Wijaya
4. Najwa Ghaysani Athata Ardyanto
