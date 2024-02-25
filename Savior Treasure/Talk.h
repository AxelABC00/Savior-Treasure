#pragma once
#include<SFML/Graphics.hpp>

class Talk {
public:
    std::string option1;
    std::string option2;
    std::string option3;
    std::string response1;
    std::string response2;
    std::string response3;
    std::string introText;
    void clear();
    Talk(const std::string& intro, const std::string& opt1, const std::string& opt2, const std::string& opt3,
        const std::string& resp1, const std::string& resp2, const std::string& resp3)
        : introText(intro), option1(opt1), option2(opt2), option3(opt3),
        response1(resp1), response2(resp2), response3(resp3) {}
    std::string getResponse(int choice) const {
        switch (choice) {
        case 1:
            return response1;
        case 2:
            return response2;
        case 3:
            return response3;
        default:
            return "";
        }
    }
};
class Baslangic : public Talk {
public:
    Baslangic() :
        Talk("Kamil Altinsever, siradan bir gun gecirirken hayatinin tamamen\ndegisecegini hic dusunmemisti. Kardesi uzun suredir hastaydi ve artik son\ngunlerini yasiyordu. Kardesinin kurtulmasi icin ameliyat olmasi sartti,\nancak ameliyat cok pahaliydi. Kamil, kardesini kurtarmak icin yola koyulmaya\nkarar verdi. Dedesi uzun yillar once hazine icin ciktigi yolda olmustu,\nve dedesi, hazinenin bulunabilmesi icin gercek sevgiye ihtiyac oldugunu\nbelirtmisti. Dedesinin bu gorevi tamamlayamamis olmasi, Kamil'i dusundurdu\nancak dedesinin sefer notlarini aldi ve yola koyuldu.\n(Cikis yapmak icin A tusuna bas.)",
            "", "", "", "", "", "") {}
};

class Muhafiz : public Talk {
public:
    Muhafiz()
        :Talk("Muhafiz : Hey yabanci! Geldigin yere dikkat et. Burada yabancilari sevmeyiz.\nBuraya neden geldin?",
            "1. Yolumu kaybettim, neredeyim bilmiyorum.",
            "2. Ben de yabancilari sevmem. Dikkatli konus. Karsinda bir hazine avcisi\nduruyor, o gizemli hazinenizi bulmaya geldim.",
            "3. Ben bir tuccarim. Buraya mal alip satmaya geldim. Pazar nerede?\n\n(Secim yapmak icin 1,2 ve 3 tuslarini kullan)",
            "Muhafiz : Kucugum, bu halinle ne isin var burda?\nBurasi tehlikeli bir yer. Bu ciliz kollarla fazla\nyasamazsin. Al bu kilici, belki faydasi olur.\nMuhtara gitmeni oneririm. Yolu takip et,\nilk kopruden gec. (Space = Fire)\nCIKIS YAPMAK ICIN A TUSUNA BAS\n",
            "Muhafiz : Hmm, tavrini sevdim. Karakterin, kollarina\ngore daha sert belli. Ey yabanci, burasi tehlikeli\nbir yer. Nedenini soylemem yasak. Sana tavsiyem,\nbu kilici al, ihtiyac halinde kullanirsin. Muhtara\ngit, o buranin en yaslisi, sana yolunu bulmanda\nyardimci olur. Yolu takip et, ilk kopruden gec.\n(Space = Fire)\nCIKIS YAPMAK ICIN A TUSUNA BAS\n",
            "Muhafiz : Tuccar kardes, burasi tehlikeli bir yer.\nBu kilici al, belki faydasi olur. Muhtara git, o\nburanin en yaslisi, sana Pazar icin yardimci olur.\nYolu takip et, ilk kopruden gec.\n(Space = Fire)\nCIKIS YAPMAK ICIN A TUSUNA BAS\n") {}
};
class Muhtar1 : public Talk {
public:
    Muhtar1()
        :Talk("Kamil : Muhtar kardes sen misin? Muhafiz beni sana yonlendirdi.\nMuhtar : Evet benim muhtar. Sorunun nedir?",
            "1. Kamil : Ben buraya gizemli hazineyi bulmak icin geldim.",
            "2. Kamil : Ey muhtar, ben tuccarim buraya soylentiler ustune geldim.\nburda cok altin varmis diye duydum.",
            "3. Kamil : Muhtar kardes ben unlu goldloverlardan Kamil.\nBuraya neden geldigimi soylememe gerek yok.",
            "Muhtar : Hic gulecegim yoktu. Burasi goruldugu gibi tatli\nve sevimli bir yer degil tehlikeler ve gizemlerin oldugu\nbir yer evet dogrudur hazine var ama hazineyi bulma yolunda\ncok insan kaybettik. Bu hazine lanetli eger hazineyi bulursak\nkoyumuz kurtulacak.\nCIKIS YAPMAK ICIN A TUSUNA BAS\n",
            "Muhtar : Tuccar kardes burasi aliskin oldugun ticaret\nseklinden farkli calisiyor dedigin altinlar lanetli bir\nsandigin icinde. Maalesef hazineyi bulmaya calisan hic kimse\ngeri donemedi...\nCIKIS YAPMAK ICIN A TUSUNA BAS\n",
            "Muhtar : Biz de sizin gibi birini bekliyorduk dedenizin ununu\nduymustum. Hazine lanetli bulmaya calisan kimse geri\ndonemedi...\nCIKIS YAPMAK ICIN A TUSUNA BAS\n") {}
};

class Muhtar2 : public Talk {
public:
    Muhtar2()
        :Talk("Kamil : Hazineyi nasil bulabilirim bana anlatir misin?",
            "Muhtar : Bu hazine gizemli yaratiklar ve bulmacalarla korunuyor.\nilk once karanlik tunellerde sakli anahtari bulman gerekiyor.\nkaranlik tunelleri bulmak icin kuzeye git, anahtari bulduktan\nsonra tekrar buraya gel.\n1'E BAS",
            "", "",
            "Kamil : Bu kadar basit demek ki ben Kamil geliyorum!\nCIKIS YAPMAK ICIN A TUSUNA BAS\n",
            "Kamil : Bu kadar basit demek ki ben Kamil geliyorum!\nCIKIS YAPMAK ICIN A TUSUNA BAS\n",
            "Kamil : Bu kadar basit demek ki ben Kamil geliyorum!\nCIKIS YAPMAK ICIN A TUSUNA BAS\n"

        ) {}
};

class Muhtar3 : public Talk {
public:
    Muhtar3()
        :Talk("Kamil karanlik tunellere gittikten sonra tekrar gelir muhtara...",
            "1. Kamil : Muhtar kardes anahtari buldum simdi ne yapmam lazim?",
            "2. Kamil : Muhtar anahtari buldum diyelim sonra ne yapmam gerekiyor?",
            "3. Kamil : Muhtar kardes anahtari cok zor buldum bu hazineyi\nbulabilecegimden supheliyim ama bana yolumu goster devam edecegim.",
            "Muhtar : Inanamiyorum sevincten aglayacagim gercekten\nanahtari buldun demek omrumun yetecegini dusunmuyordum\ngormek nasip oldu cok sukur. Bu hazine gizemli uc kardes\nyaratik tarafindan korunuyor. Bunlarin isimleri Razador\nKardesler. Bu gizemli yaratiklar cok guclu onlari yenmek\nicin guc iksirine ihtiyacin var. bu guc iksiri bir tekerlemede\ngizli sana bunu soylecegim ama bana hazineyi koyumuzun\nlanetten kurtulmasi icin kullacagina karsi soz vermen\ngerekiyor.\n(CIKIS YAPMAK ICIN A TUSUNA VE TEKRAR IKI KERE E'YE BAS.)",
            "Muhtar : Bu hazine gizemli uc kardes yaratik tarafindan\nkorunuyor. Bunlarin isimleri Razador Kardesler. Bu gizemli\nyaratiklar cok guclu onlari yenmek icin guc iksirine\nihtiyacin var.\nbu guc iksiri bir tekerlemede gizli. sana bunu soylecegim\nama bana hazineyi koyumuzun lanetten kurtulmasi icin\nkullacagina karsi soz vermen gerekiyor.\n(CIKIS YAPMAK ICIN A TUSUNA VE TEKRAR IKI KERE E'YE BAS.)",
            "Muhtar : Bu hazine gizemli uc kardes yaratik tarafindan\nkorunuyor. Bunlarin isimleri Razador Kardesler. Bu gizemli\nyaratiklar cok guclu onlari yenmek icin guc iksirine\nihtiyacin var.\nbu guc iksiri bir tekerlemede gizli. sana bunu soylecegim\nama bana hazineyi koyumuzun lanetten kurtulmasi icin\nkullacagina karsi soz vermen gerekiyor.\n(CIKIS YAPMAK ICIN A TUSUNA VE TEKRAR IKI KERE E'YE BAS.)"
        ) {}
};

class Muhtar4 : public Talk {
public:
    Muhtar4()
        :Talk("",
            "1. Kamil : Soz veriyorum amacim sadece bulmak.",
            "2. Kamil : Altinlar benim oldugu surece tabi yardim ederim. Ben Kamil\npara buldum.",
            "3. Kamil : Soz veriyorum! (ic ses : kardesim hasta paraya ihtiyacim var\nyalan soylemek istemezdim.)",
            "Muhtar: koyumuz bu iyiligi unutmayacak.\nTekerleme su sekilde :\nGecenin perdesi ardinda, gizemli bir dansa burunduler;\nbir cift kirmizi, iki dost gulerken dokuldu cekirdekleri,\nsari hilal gulumsedi, baska bir bahcenin kapisini araladi,\ngeliyor gelecek baharlar. Bu bilmeceyi cozdugun zaman\ndoguya git orada seker adasini goreceksin iksiri\nhazirladiktan sonra buraya gel.(2 elma 2 karpuz 1 muz)\n(CIKIS YAPMAK ICIN A TUSUNA BAS)",
            "Muhtar: koyumuz bu iyiligi unutmayacak.\nTekerleme su sekilde :\nGecenin perdesi ardinda, gizemli bir dansa burunduler;\nbir cift kirmizi, iki dost gulerken dokuldu cekirdekleri,\nsari hilal gulumsedi, baska bir bahcenin kapisini araladi,\ngeliyor gelecek baharlar. Bu bilmeceyi cozdugun zaman\ndoguya git orada seker adasini goreceksin iksiri\nhazirladiktan sonra buraya gel.(2 elma 2 karpuz 1 muz)\n(CIKIS YAPMAK ICIN A TUSUNA BAS)",
            "Muhtar: koyumuz bu iyiligi unutmayacak.\nTekerleme su sekilde :\nGecenin perdesi ardinda, gizemli bir dansa burunduler;\nbir cift kirmizi, iki dost gulerken dokuldu cekirdekleri,\nsari hilal gulumsedi, baska bir bahcenin kapisini araladi,\ngeliyor gelecek baharlar. Bu bilmeceyi cozdugun zaman\ndoguya git orada seker adasini goreceksin iksiri\nhazirladiktan sonra buraya gel.(2 elma 2 karpuz 1 muz)\n(CIKIS YAPMAK ICIN A TUSUNA BAS)"
        ) {}
};

class Muhtar5 : public Talk {
public:
    Muhtar5()
        :Talk("",
            "1. Kamil : Muhtar benim iksire ihtiyacim yok ben goldloverim tek ihtiyacim\nolan sey kalbimdeki inanc!",
            "2. Kamil : Iksiri hazirladim bana simdi ne yapacagimi soyle.",
            "3. Kamil : Iksiri hazirlamak anahtari bulmaktan daha kolay...",
            "Muhtar : ununun hakkini veriyorsun. artik sona geldik.\nRazador Kardesleri yenmek kaldi. Bu canavarlari her ne\nkadar guc iksirini kullanmis olsan bile sadece sozunun eri\nolmak ve saf sevgi yenebilir.\nRazador Kardesleri yenmek icin guneye git.\n(CIKIS YAPMAK ICIN A TUSUNA VE TEKRAR IKI KERE E'YE BAS.)",
            "Muhtar : ununun hakkini veriyorsun deden senle gurur\nduyardi. artik sona geldik Razador Kardesleri yenmek kaldi.\nBu canavarlari her ne kadar guc iksirini kullanmis olsan\nbile sadece sozunun eri ve saf sevgi yenebilir.\nRazador Kardesleri yenmek icin guneye git.\n(CIKIS YAPMAK ICIN A TUSUNA VE TEKRAR IKI KERE E'YE BAS.)",
            "Muhtar : ununun hakkini veriyorsun deden senle gurur\nduyardi. artik sona geldik Razador Kardesleri yenmek kaldi.\nBu canavarlari her ne kadar guc iksirini kullanmis olsan\nbile sadece sozunun eri ve saf sevgi yenebilir.\nRazador Kardesleri yenmek icin guneye git.\n(CIKIS YAPMAK ICIN A TUSUNA VE TEKRAR IKI KERE E'YE BAS.)"
        ) {}
};

class Muhtar6 : public Talk {
public:
    Muhtar6()
        :Talk("Kamil : Ben kamil sozumden donmem donmeyecegim o hazine bulunacak yola\ncikiyorum.",
            "Muhtar : dikkat et bulduktan sonra hazinenin laneti sana da bulasacak\ndogru yoldan vazgecme.\n(CIKIS YAPMAK ICIN A TUSUNA BAS.)"
            "", "", "", "", "", ""
        ) {}
};

class FinalChoice : public Talk {
public:
    FinalChoice()
        : Talk("Son Secim Zamani",
            "1. Secim : hazineyi kardesini kurtarmak icin kullan ve koyun sonsuza kadar\nlanetle kalmasina goz yum.",
            "2. Secim : hazineyi muhtara ver sozunde dur muhtar kardesim icin sana\nyardimci olabilir.",
            "3. Secim : artik dunyadaki en zengin canlisin ne kardesi ne koyu!\nYeni bir hayat kur hazineyi kendine sakla. koyun lanetli kalmasina\ngoz yum, kardesin olsun.",
            "1. secim sonucu : Kardesinin ameliyati basarili gecti artik\nsaglikli lakin sozunden dondugun icin koy yerle bir oldu.\nHayatinin sonuna kadar bunu dusunerek gecirdin kahrindan\noldun.\n(OYUN SONU ICIN A TUSUNA VE IKI KERE E'YE BAS)",
            "2. secim sonucu : Her seyi goze alarak muhtara hazineyi\nverdin. sonra bunlarin hepsinin aslinda gercek olmadigini\nbunun ilahi gucler tarafindan sana uygulanan bir test\noldugunu ogrendin aslinda muhtar gercek degil, kardesin\ngercekten hasta degil, koy gercekten yok artik ne olacagini\nbilmiyorsun.\n(OYUN SONU ICIN A TUSUNA VE IKI KERE E'YE BAS)",
            "3. secim sonucu : dunyanin en zengin ve en mutlu insanisin\nartik her sey elinin altinda ailen seni terk etti. kardesine\nyardimci olmadigin icin ama bunu sorun etmedin.\n(OYUN SONU ICIN A TUSUNA VE IKI KERE E'YE BAS)"
        ) {}
};
class Bitis : public Talk {
public:
    Bitis()
        : Talk("Yasam, alinan her kararin bir iz biraktigi bir yoldur; o yollar, zamanla\nbiriktikce, insanin hayat haritasini cizer ve kimligini sekillendirir...",
            "", "", "", "", "", ""
        ) {}
};