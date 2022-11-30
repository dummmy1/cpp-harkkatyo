# cpp harkkatyö


##### Minun tekemä c++ kurssin harjotustyö, aiheena tehdä hotellin huoneenvaraus-järjestelmä


Ohjeet työn tekemiseen:

'''cpp
Harjoitustyö
Harjoitustyön tarkoitus

Ohjelmoinnin perusteiden harjoitustyön tarkoituksena on koota yhteen kurssilla opitut asiat toimivalla ja hyvin suunnitellulla C++ -ohjelmalla.

Harjoitustyössä tulee luonnostaan käytettyä ohjelmoinnin perusrakenteita (muuttujat, valinta- ja toistorakenteet, loogiset operaattorit, aritmetiikka jne.) Hyvin toteutettu harjoitustyö täyttää myös seuraavat ominaisuudet:

Ohjelmakoodi on jaoteltu järkevästi pääohjelmaan ja aliohjelmiin eli itse kirjoitettuja ja tarvittaessa valmiiden kirjastojen aliohjelmia on hyödynnettyä sopivissa kohdin (kiitettävässä työssä vähintään 2 omaa aliohjelmaa)
Kaikilla ohjelman muuttujilla ja aliohjelmilla on kuvaavat nimet
Taulukoiden hyödyntäminen tiedon säilömisessä ja haussa
Koodi on hyvin kommentoitu
Ohjelmassa ei saa käyttää globaaleja muuttujia, sen sijaan globaaleja vakioita voi käyttää (ja on suotavaakin käyttää tarpeen vaatiessa).
Ohjelma ei kaadu virheellisiin syötteisiin (eikä tietenkään muutenkaan :)
Työn suorittaminen yksilötyönä

Harjoitustyö on yksilötyö. Työn kopiointi (toiselta kurssilaiselta, netistä tms.) on ehdottomasti kielletty ja johtaa hylättyyn arvosanaan. Tosin neuvoa voi kaverilta kysyä tarpeen tullen :)

Harjoitustyön palautus ja aikataulu

Harjoitustyön tulee olla valmis ja palautettuna Gittiin viimeistään torstaina 15.12. klo 23.45 Työstä palautetaan kaikki kooditiedostot sekä lyhyt, 1–2 sivun kuvaus työn sisällöstä ja ohjelman toiminnasta (PDF). 

Harjoitustyöosion karkeat arviointikriteerit

Arvosana 0 - Harjoitustyötä ei palautettu.

Arvosana 1 - Harjoitustyö on toteutettu "sinne päin", mutta työssä on isoja puutteita, eikä se toimi halutulla tavalla.

Arvosana 2 - Harjoitustyö toteuttaa halutun tehtävän suurin piirtein, mutta työssä on selkeitä puutteita tai bugeja tai harjoitustyö on liian suppea.

Arvosana 3 - Harjoitustyö on hyvä ja selkeä perustoteutus, joka täyttää työlle asetetut vaatimukset ilman selkeitä putteita. Hyvää ja hyvin dokumentoitua ohjelmakoodia, eikä isoja puutteita esiinny.

Arvosana 4 - Harjoitustyö on keskivertoa vaativampi toteutettu erittäin hyvin ja ylittää laadullisesti selkeästi keskivertototeutuksen. Työ on toteutettu hyvällä ohjelmointityylillä ja loogisesti ja selkeästi modularisoitu kokonaisuus.

Arvosana 5 - Työ on toteutettu kaikin puolin poikkeuksellisen hyvin ja työ erottuu selkeästi edukseen erittäin hyvien töiden joukosta.

Harjoitustyö – C++ perusteet – Hotellihuoneen varausohjelma

Hotellihuoneen varausohjelmassa arviointikriteerit ovat:

1 pisteen (ykkösen) ohjelma:

Hotellissa on n huonetta, numerot 1-n. Huoneiden lukumäärä määritetään ohjelmaan vakiona. Käyttäjä varaa huoneen valiten itse huoneen numeron. Jos huone on jo varattu, ohjelma pyytää valitsemaan toisen huonenumeron.  Huoneen hinta on 100 euroa yöltä. Käyttäjä antaa öiden määrän, ja ohjelma ilmoittaa laskun loppusumman.

Ohjelma on valmis varaamaan huoneita niin kauan kuin käyttäjä haluaa, kuitenkin enintään n huonetta. Tässä riittää, kun syötteen tarkistuksessa tarkistetaan, että se on luku välillä 1-n.

 2–3 pisteen (kakkosen-kolmosen) ohjelma:

Kuten edellinen, mutta ohjelma arpoo aluksi huoneiden kokonaismäärän väliltä 30-70 ja hinnan yöltä väliltä 80-100 euroa. Ohjelma arpoo huoneen numeron vapaana olevista huoneista. Ohjelmassa on muodostettu ainakin yksi aliohjelma.  (2-3 p sen mukaan, miten hyvin ohjelma toimii ja lisäyksissä on onnistuttu.) Syötteen tarkistus kattaa myös ei-numerot.

 4–5 pisteen (nelosen-vitosen) ohjelma:

Kuten edellä, mutta huoneita on parillinen määrä välillä 40–300, ja niistä puolet (alkupuoli) on yhden hengen ja puolet (loppupuoli) kahden hengen huoneita. Ohjelman valikko pitää olla toteutettu monipuolisesti ja havainnollisesti. Ohjelman pitää suoriutua mahdollisista ongelmatilanteista. Ohjelmassa voidaan varattavat huoneet joko arpoa koneella tai valita käyttäjän toimesta. Varmistu kuitenkin aina siitä, että huonetyyppi on saatavilla(varattavissa).

Huonehinnat ovat

·         1hh: 100 euroa yöltä ja  

·         2hh: 150 euroa yöltä,

Ohjelma arpoo, annetaanko huoneiden loppuhintaan 0 %:n, 10 %:n vai 20 %:n alennus.

Käyttäjä antaa huonekoon ja öiden määrän, ja ohjelma ilmoittaa laskun loppusumman mahdollisen alennuksen jälkeen.

Ohjelma on valmis varaamaan huoneita niin kauan kuin käyttäjä haluaa, kuitenkin enintään em. määrät yhden ja kahden hengen huoneita. Ohjelma tarkistaa aina huonetyypin ennen varausta, jotta voidaan varmistua niiden saatavuudesta.

Ohjelmassa on muodostettu ainakin kaksi olennaisesti erilaista aliohjelmaa.

 (4-5 p sen mukaan, miten hyvin ohjelma toimii ja lisäyksissä on onnistuttu.)

 

Tärkeää:

Kaikissa yllä mainituissa vaihtoehdoissa on tehtävä virheentarkistus käyttäjän syötteille! 4-5 p työssä listaa lisäksi palautuksen kommenttikenttään ne lisäominaisuudet, jotka olet toteuttanut. Merkitse myös minkä arvosanan mukaisesti olet mielestäsi toteuttanut työn.  

 

Muita harjoitustyön rajauksia, jotka tulee ottaa lopputyössä huomioon:

Varausnumero: (int) on oltava välillä 10000-99999. Ohjelma arpoo varausnumeron satunnaisesti.

Varaajan nimi: (string) esim. Juha Ranta-Ojala, käytä siis getline -komentoa syötteen lukemiseen.

Uutta varausta tehdessäsi, tarkista ensin kyseisen huoneen varaus boolean tyyppisellä aliohjelmalla.

Huoneet -taulukon (tai vektorin) ylärajan voit asettaa 300 huoneeseen. Jos huoneita on tuo

maksimimäärä, niin silloin yhden hengen huoneita on max. 150kpl ja kahden hengen 150kpl.

Ohjelmassa pitää olla mahdollisuus tehdä hakuja varauksiin joko varausnumerolla tai varaajan nimellä.

 

Ohjelman menun rakenteen voit itse suunnitella. Varmistu kuitenkin ensin siitä, että olet ottanut

huomioon sen, mitkä osat ohjelmassa kuuluu toteuttaa. Voit lisäksi tehdä ohjelmaan omia lisäyksiä

sen mukaan, kun aikaa ja energiaa riittää ohjelman tekemiseen. Tähän on loppukurssi aikaa varattuna.

Älä yritä mennä siitä, mistä aita on matalin, vaan haasta itsesi ja pyri aina parhaaseen lopputulokseen.

Ennen kuin alat tekemään varsinaista koodausosuutta, suunnittele ohjelmassa tarvittavat asiat ja niiden

toteutus huolella. Tämä tulee säästämään sinulta paljon aikaa varsinaisen koodin kirjoitusvaiheessa.'''
