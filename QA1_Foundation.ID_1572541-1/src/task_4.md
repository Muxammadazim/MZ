# Task 4. Sinov tamoyillari (7 ta prinsip)

## 1) 7 ta sinov tamoyili (kamida 2 ta ishonchli manba bilan)

Manbalar:
1) ISTQB Certified Tester Foundation Level Syllabus (CTFL v4.0.1) — rasmiy PDF: https://istqb.org/?download_id=3345&sdm_process_download=1  
2) imbus — “Seven principles of software testing”: https://www.imbus.ca/software-testing/seven-principles-of-software-testing  
(Qo‘shimcha: ASTQB sahifasi ham shu mavzuni CTFL bo‘limi sifatida beradi: https://astqb.org/istqb-foundation-level-seven-testing-principles/)

### 1. Testing shows the presence of defects, not their absence  
Testlar nuqson borligini ko‘rsatishi mumkin, lekin “nuqson yo‘q”ligini isbotlay olmaydi. Test natijasi xavfni kamaytiradi, ammo 100% kafolat bermaydi.  
(Manba: ISTQB CTFL v4.0.1; imbus)

### 2. Exhaustive testing is impossible  
Barcha kombinatsiyalarni, barcha sharoitlarni va barcha kirishlarni to‘liq sinab chiqish amalda imkonsiz. Shu sabab testlar risk va ustuvorlikka tayangan holda tanlanadi.  
(Manba: ISTQB CTFL v4.0.1; imbus)

### 3. Early testing saves time and money (Shift-left)  
Testlashni qanchalik erta boshlasak (talablar, dizayn, kod sharhi), xatoni tuzatish shunchalik arzon va tez bo‘ladi. Kech topilgan xatolar ko‘pincha qimmatga tushadi.  
(Manba: ISTQB CTFL v4.0.1; imbus)

### 4. Defect clustering  
Ko‘p nuqsonlar odatda tizimning kichik qismida “to‘planadi” (murakkab, tez o‘zgaradigan yoki riskli modullar). Shuning uchun test resursini eng muammoli joylarga ko‘proq berish foydali.  
(Manba: ISTQB CTFL v4.0.1; imbus)

### 5. Pesticide paradox  
Bir xil testlarni doimiy takrorlash vaqt o‘tib yangi nuqsonlarni kamroq topishga olib keladi. Testlarni yangilab turish, yangi ssenariylar qo‘shish va regressiyani “tirik” saqlash kerak.  
(Manba: ISTQB CTFL v4.0.1; imbus)

### 6. Testing is context dependent  
“Hammasiga bir xil” test yondashuvi yo‘q: banking tizimi, o‘yin, tibbiy dastur, AI modeli — har birining risklari va test strategiyasi boshqacha bo‘ladi.  
(Manba: ISTQB CTFL v4.0.1; imbus)

### 7. Absence-of-errors is a fallacy  
Agar tizimda ko‘p xato topilmasa ham, u foydalanuvchi ehtiyojini qondirmasa baribir muvaffaqiyatsiz bo‘lishi mumkin. Demak, “bug yo‘q” — “foydali va to‘g‘ri” degani emas.  
(Manba: ISTQB CTFL v4.0.1; imbus)

---

## 2) Shaxsiy fikrim: muhimligiga ko‘ra tartiblash (Top-3 va eng kam muhim 1 ta)

### Eng muhim 3 ta tamoyil (muvaffaqiyatga eng ko‘p ta’sir qiladi)
1) **Early testing saves time and money**  
   Sabab: xatoni erta topish ham vaqt, ham byudjet, ham jamoa ishonchini saqlaydi.
2) **Testing is context dependent**  
   Sabab: loyiha turiga mos strategiya bo‘lmasa, testlar “ko‘p” bo‘lsa ham qiymat bermaydi.
3) **Exhaustive testing is impossible**  
   Sabab: resurs cheklangan sharoitda riskga asoslangan (prioritetli) testlashni majbur qiladi.

### Eng kam muhim (1 ta) — nisbiy baho
7) **Pesticide paradox**  
   Izoh: bu prinsip muhim, lekin menimcha u ko‘proq “testlarni saqlash va rivojlantirish” bosqichida kuchli seziladi. Ba’zi kichik yoki qisqa muddatli loyihalarda uning ta’siri qolgan prinsiplar kabi tez bilinmasligi mumkin.

---

## 3) Zamonaviy voqelik (DevOps, AI, low-code) hisobga olinib qo‘shimcha yoki takomillashtiriladigan tamoyillar

Quyidagi yangilanishlar / yangi prinsiplar klassik 7 tamoyilni inkor etmaydi, balki ularni bugungi amaliyotga moslashtiradi:

### A) “Continuous testing” va tez feedback (DevOps/CI-CD uchun)
Taklif: testlash “bosqich” emas, balki doimiy oqim bo‘lishi kerak.  
Amaliy ko‘rinish: CI/CD’da avtomatik testlar, code review, statik analiz, pipeline gate’lar, monitoring natijalariga qarab tez tuzatish.

### B) “Observability / Shift-right” — prod muhitda ham sifatni kuzatish
Taklif: faqat pre-release testlar yetarli emas; real foydalanuvchi muhitida metrikalar va loglar orqali sifat nazorati davom etadi.  
Amaliy ko‘rinish: error rate, latency, crash analytics, feature flag, A/B test, canary release.

### C) “Test automation is a product”
Taklif: test avtomatlashtirish ham kod kabi qo‘llab-quvvatlanadi: sifatli, o‘qiladigan, barqaror bo‘lishi kerak.  
Amaliy ko‘rinish: flaky testlarni kamaytirish, test arxitekturasi, test data boshqaruvi, pipeline tezligi.

### D) AI/ML testlari uchun “data va model drift” prinsipini kiritish
Taklif: AI tizimlarda sifat faqat kodga bog‘liq emas — ma’lumot va model xulqi vaqt o‘tishi bilan o‘zgaradi.  
Amaliy ko‘rinish: data quality checks, bias/fairness tekshiruvi, drift monitoring, qayta o‘qitish (retraining) siyosati, “golden dataset”.

### E) Low-code / no-code uchun “konfiguratsiya va integratsiya risklari”ni alohida ko‘rish
Taklif: bunday platformalarda xato ko‘pincha koddan ko‘ra konfiguratsiya, rol/huquq, integratsiya yoki workflow’da bo‘ladi.  
Amaliy ko‘rinish: permission testing, integration contract test, workflow edge-case’lar, audit log tekshiruvi.

---

## Xulosa
Klassik 7 prinsip bugun ham asosiy poydevor bo‘lib qoladi. Ammo DevOps va AI davrida testlashni “erta” boshlash bilan birga uni “doimiy” va “kuzatuvli” qilish (CI/CD + monitoring), shuningdek AI va low-code’ning o‘ziga xos risklarini (data drift, konfiguratsiya) alohida prinsip sifatida ko‘rish foydali.
