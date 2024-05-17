# Airsoft-C4-Litterbach

# ZADÁNÍ

* V tomto projektu bylo mým cílem vytvořit realistickou repliku výbušniny C4 z populární hry Counter-Strike. Kromě vizuální napodobeniny jsem řešil funkčnost několika částí a zda bude v celku fungovat (aktivace a deaktivace výbušniny, LED diody, bzučák,…)

* Výbušnina by mohla sloužit jako replika C4 pro Airsoft události.

# POROVNÁNÍ TEXTURY ZE HRY S KOPIÍ

![image](https://cdn.discordapp.com/attachments/888092043803504730/1241105452851269732/csc4texture.png?ex=6648fd06&is=6647ab86&hm=067ca8167984efe412f07649b95a46f2cf91a2a9e66cfc23e89745a7e19c5933&) ![image](https://cdn.discordapp.com/attachments/888092043803504730/1241105452608127102/csc4irl.png?ex=6648fd06&is=6647ab86&hm=4b0224bea5126a228146ff6fdcd65305379026c8f3e8b31226050ed9bb468c19&)

# SCHÉMA ZAPOJENÍ

![image](https://cdn.discordapp.com/attachments/888092043803504730/1241111197965746218/Vystrizek.PNG?ex=66490260&is=6647b0e0&hm=255efdacc2c88dc32b3b883f21b73613d86d2d6855345c2f19b3436b2020fc10&)

# PŘÍPRAVA, POSTUP, POPIS A FOTKY

### 1. MATERIÁL:

a) Vizuální část: Kartonová krabice (13cm x 19cm x 4,5cm), šedá textilní lepící páska, lepidlo, tavící pistole, 9V baterie, černý fix, dráty.

b) Elektronika: Arduino Nano, I2Cx2 LCD Displej s integrovaným obvodem, membránová klávesnice 4x3, bzučák, dráty, nepájivé pole, LED diody, 1x rezistor 330ohm, 2x rezistor 220ohm.

### 2. FOTKY:

![image](https://cdn.discordapp.com/attachments/888092043803504730/1241114047336677437/696C6ED7-208D-45B3-A180-6A7A6C03B23C.jpg?ex=66490507&is=6647b387&hm=ac4b674562e8d82aba58c91f95b67c873da108a39783d04ee93b2276589e75d3&) ![image](https://cdn.discordapp.com/attachments/888092043803504730/1241114046971908176/182B3470-330A-43CF-B3BA-EE7E0609CBCB.jpg?ex=66490507&is=6647b387&hm=c233ab701bc1567c1ccc19e6656215cea027c9e91ddd288f062836a797491574&) ![image](https://cdn.discordapp.com/attachments/888092043803504730/1241114046694948916/C794CA2C-D8F6-43BC-BC24-CAA8A3E08781.jpg?ex=66490507&is=6647b387&hm=f68cad9c923822591a6bc8651edd53682c32d54a479d58b7b607f752c0071b50&) ![image](https://cdn.discordapp.com/attachments/888092043803504730/1241114045264826458/2E807ED2-5CFD-4A8B-A55E-A033DE5DEBFC.jpg?ex=66490507&is=6647b387&hm=0a79537ff17d04f379be5ee1bd130029c379aaf0e07db98de3c26116079d2b45&) ![image](https://cdn.discordapp.com/attachments/888092043803504730/1241114045675737088/9D60E382-7BE4-41D9-BCF8-B285F3A6BF5E.jpg?ex=66490507&is=6647b387&hm=44e41427304c992bea0daa9ef6415128029824b3cfdbd2b4c570af84c1c77a92&) ![image](https://cdn.discordapp.com/attachments/888092043803504730/1241114046057414676/84446D6F-63CD-40CD-BB98-EE4A585FA66D.jpg?ex=66490507&is=6647b387&hm=87e70b157ac641b8f5e32a92fd770edf99563c0435f8836752fb5cb9777dd32d&) ![image](https://cdn.discordapp.com/attachments/888092043803504730/1241114047735271474/AAAA7F8C-CBDB-49D3-AEE9-641A1301345C.jpg?ex=66490507&is=6647b387&hm=b1f5d3f820cc2894e1dbc0e40f24080c9fa11c052d642eefddd3a4b281287c70&)

### 3. POPIS A POSTUP:

* Místo skládání kartonových krabiček jsem zvolil rovnou jednu v celku kterou jsem měl po ruce. Její rozměry (13cm x 19cm x 4,5cm) stačí přesně na to, aby se do/na ní vešlo vše co je potřeba. Na vnější straně je membránová klávesnice, do které jsem ze vnitř skrz karton prostrčil drátky a poté je napájel. 

  Skrz karton prochází také diody (zelená, žlutá a červená), které jsem zevnitř připevnil tavící pistolí.
Ty se nachází pod LCD displejem, do kartonu jsem udělal dostatečně velký otvor pro integrovaný obvod a jak displej, tak keypad jsem ke krabici připevnil tavící pistolí.

  Pro detail jsem krabici oblepil lepící páskou společně s 9V baterií, jež slouží jen pro desing, společně s drátky které jsou natáhnuty po kartonové ploše.

  Fixem jsem pak už jen doladil nejmenší detaily.

* Vnitřní část: Jelikož jsem zvolil již předem složenou krabici, dokázal jsem se tak jednoduše dostat dovnitř před zadní stranu, která se dá otevřit.

  Uvnitř je nalepené nepájivé pole, na něm Arduino Nano a všechny další částí hardwaru (např. bzučák na pinu 9). Na levé části Arduina jsou připojený piny pro keypad. Na pravé straně zase LED diody a LCD displej. 

  Jak už jsem zmínil diody jsou přitaveny pevně ke krabici a k červené diodě jsem přiřadil rezisotr o 330 ohm., k zelené a žluté diodě zas 220 ohm.

  Nad diodami je integrovaný obvod LCD displeje, kde je možné si nastavit jasnost displeje.

  Celý zařízení je napájeno USB kabelem, ze strany pod batrerií lze kabel prostrčit. Dráty, které mají podobné využití nebo slouží ke stejné věci jsem obmotal jiným drátkem, aby tak uvnitř krabice nevznikalo šílenství.

# KÓD:

Přidal jsem nahoře k této prezentaci i složku s celým kódem v Arduinu. Snažil jsem se ho popsat do detailů, ale mnoho příkazů se tam opakuje (s rozdílem např. hodiny, minuty, vteřiny), takže jsem popsal jen první část a další podobný jsem vynechal.

# ZDROJE A POMOC:

* Zdroje: Jak už jsem zmiňoval v prvním pololetí, inspirací jsem měl dost, nakonec jsem ale čerpal čistě z této stránky: https://www.viralsciencecreativity.com/post/arduino-airsoft-bomb, z které jsem využil kód a zapojení hardwaru.

* Pomoc: Jakub Kučera byl ochoten mi spájet dráty k membránové klávesnici, jelikož jsem na tohle a podobné miniaturní věci neschopný nervák, zároveň mi do-zkontroloval hardware, zda je všechno v pořádku.
