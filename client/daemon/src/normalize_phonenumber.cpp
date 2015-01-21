#include "normalize_phonenumber.h"
#include <QRegularExpression>
#include <QDebug>

normalize_phonenumber::normalize_phonenumber(QObject *parent) :
    QObject(parent)
{
}


// normalize to format in contacts.db
QString normalize_phonenumber::process(QString number) {
    QRegularExpression filter("[^0-9]");

    qDebug() << "normalized number = " << number.replace(filter, "").right(8);

    return number.replace(filter, "").right(8);
}

QString normalize_phonenumber::international_to_local(QString number) {

    if(number.startsWith("0046") || number.startsWith("+46")) {
        return number.replace("+46", "0").replace("0046", "0");
    }

    return number;

}



QString normalize_phonenumber::mobilecc_to_iso32662(int code) {

    QMap<int, QString> mccList;

    mccList.insert(202, "GR");
    mccList.insert(204, "NL");
    mccList.insert(206, "BE");
    mccList.insert(208, "FR");
    mccList.insert(212, "MC");
    mccList.insert(213, "AD");
    mccList.insert(214, "ES");
    mccList.insert(216, "HU");
    mccList.insert(218, "BA");
    mccList.insert(219, "HR");
    mccList.insert(220, "RS");
    mccList.insert(222, "IT");
    mccList.insert(226, "RO");
    mccList.insert(228, "CH");
    mccList.insert(230, "CZ");
    mccList.insert(231, "SK");
    mccList.insert(232, "AT");
    mccList.insert(234, "GB");
    mccList.insert(235, "GB");
    mccList.insert(238, "DK");
    mccList.insert(240, "SE");
    mccList.insert(242, "NO");
    mccList.insert(244, "FI");
    mccList.insert(246, "LT");
    mccList.insert(247, "LV");
    mccList.insert(248, "EE");
    mccList.insert(250, "RU");
    mccList.insert(255, "UA");
    mccList.insert(257, "BY");
    mccList.insert(259, "MD");
    mccList.insert(260, "PL");
    mccList.insert(262, "DE");
    mccList.insert(266, "GI");
    mccList.insert(268, "PT");
    mccList.insert(270, "LU");
    mccList.insert(272, "IE");
    mccList.insert(274, "IS");
    mccList.insert(276, "AL");
    mccList.insert(278, "MT");
    mccList.insert(280, "CY");
    mccList.insert(282, "GE");
    mccList.insert(283, "AM");
    mccList.insert(284, "BG");
    mccList.insert(286, "TR");
    mccList.insert(288, "FO");
    mccList.insert(289, "GE");
    mccList.insert(290, "GL");
    mccList.insert(292, "SM");
    mccList.insert(293, "SI");
    mccList.insert(294, "MK");
    mccList.insert(295, "LI");
    mccList.insert(297, "ME");
    mccList.insert(302, "CA");
    mccList.insert(308, "PM");
    mccList.insert(310, "GU");
    mccList.insert(310, "US");
    mccList.insert(311, "GU");
    mccList.insert(311, "US");
    mccList.insert(312, "US");
    mccList.insert(316, "US");
    mccList.insert(330, "PR");
    mccList.insert(334, "MX");
    mccList.insert(338, "JM");
    mccList.insert(340, "FG");
    mccList.insert(340, "GP");
    mccList.insert(340, "MQ");
    mccList.insert(342, "BB");
    mccList.insert(344, "AG");
    mccList.insert(346, "KY");
    mccList.insert(348, "VG");
    mccList.insert(350, "BM");
    mccList.insert(352, "GD");
    mccList.insert(354, "MS");
    mccList.insert(356, "KN");
    mccList.insert(358, "LC");
    mccList.insert(360, "VC");
    mccList.insert(362, "AN");
    mccList.insert(362, "CW");
    mccList.insert(363, "AW");
    mccList.insert(364, "BS");
    mccList.insert(365, "AI");
    mccList.insert(366, "DM");
    mccList.insert(368, "CU");
    mccList.insert(370, "DO");
    mccList.insert(372, "HT");
    mccList.insert(374, "TT");
    mccList.insert(376, "TC");
    mccList.insert(376, "VI");
    mccList.insert(400, "AZ");
    mccList.insert(401, "KZ");
    mccList.insert(402, "BT");
    mccList.insert(404, "IN");
    mccList.insert(405, "IN");
    mccList.insert(410, "PK");
    mccList.insert(412, "AF");
    mccList.insert(413, "LK");
    mccList.insert(414, "MM");
    mccList.insert(415, "LB");
    mccList.insert(416, "JO");
    mccList.insert(417, "SY");
    mccList.insert(418, "IQ");
    mccList.insert(419, "KW");
    mccList.insert(420, "SA");
    mccList.insert(421, "YE");
    mccList.insert(422, "OM");
    mccList.insert(424, "AE");
    mccList.insert(425, "IL");
    mccList.insert(425, "PS");
    mccList.insert(426, "BH");
    mccList.insert(427, "QA");
    mccList.insert(428, "MN");
    mccList.insert(429, "NP");
    mccList.insert(430, "AE");
    mccList.insert(431, "AE");
    mccList.insert(432, "IR");
    mccList.insert(434, "UZ");
    mccList.insert(436, "TK");
    mccList.insert(437, "KG");
    mccList.insert(438, "TM");
    mccList.insert(440, "JP");
    mccList.insert(441, "JP");
    mccList.insert(450, "KR");
    mccList.insert(452, "VN");
    mccList.insert(454, "HK");
    mccList.insert(455, "MO");
    mccList.insert(456, "KH");
    mccList.insert(457, "LA");
    mccList.insert(460, "CN");
    mccList.insert(466, "TW");
    mccList.insert(467, "KP");
    mccList.insert(470, "BD");
    mccList.insert(472, "MV");
    mccList.insert(502, "MY");
    mccList.insert(505, "AU");
    mccList.insert(510, "ID");
    mccList.insert(514, "TP");
    mccList.insert(515, "PH");
    mccList.insert(520, "TH");
    mccList.insert(525, "SG");
    mccList.insert(528, "BN");
    mccList.insert(530, "NZ");
    mccList.insert(537, "PG");
    mccList.insert(539, "TO");
    mccList.insert(540, "SB");
    mccList.insert(541, "VU");
    mccList.insert(542, "FJ");
    mccList.insert(544, "AS");
    mccList.insert(545, "KI");
    mccList.insert(546, "NC");
    mccList.insert(547, "PF");
    mccList.insert(548, "CK");
    mccList.insert(549, "WS");
    mccList.insert(550, "FM");
    mccList.insert(552, "PW");
    mccList.insert(553, "TV");
    mccList.insert(555, "NU");
    mccList.insert(602, "EG");
    mccList.insert(603, "DZ");
    mccList.insert(604, "MA");
    mccList.insert(605, "TN");
    mccList.insert(606, "LY");
    mccList.insert(607, "GM");
    mccList.insert(608, "SN");
    mccList.insert(609, "MR");
    mccList.insert(610, "ML");
    mccList.insert(611, "GN");
    mccList.insert(612, "CI");
    mccList.insert(613, "BF");
    mccList.insert(614, "NE");
    mccList.insert(615, "TG");
    mccList.insert(616, "BJ");
    mccList.insert(617, "MU");
    mccList.insert(618, "LR");
    mccList.insert(619, "SL");
    mccList.insert(620, "GH");
    mccList.insert(621, "NG");
    mccList.insert(622, "TD");
    mccList.insert(623, "CF");
    mccList.insert(624, "CM");
    mccList.insert(625, "CV");
    mccList.insert(626, "ST");
    mccList.insert(627, "GQ");
    mccList.insert(628, "GA");
    mccList.insert(629, "CG");
    mccList.insert(630, "CD");
    mccList.insert(631, "AO");
    mccList.insert(632, "GW");
    mccList.insert(633, "SC");
    mccList.insert(634, "SD");
    mccList.insert(635, "RW");
    mccList.insert(636, "ET");
    mccList.insert(637, "SO");
    mccList.insert(638, "DJ");
    mccList.insert(639, "KE");
    mccList.insert(640, "TZ");
    mccList.insert(641, "UG");
    mccList.insert(642, "BI");
    mccList.insert(643, "MZ");
    mccList.insert(645, "ZM");
    mccList.insert(646, "MG");
    mccList.insert(647, "RE");
    mccList.insert(648, "ZW");
    mccList.insert(649, "NA");
    mccList.insert(650, "MW");
    mccList.insert(651, "LS");
    mccList.insert(652, "BW");
    mccList.insert(653, "SZ");
    mccList.insert(654, "KM");
    mccList.insert(655, "ZA");
    mccList.insert(657, "ER");
    mccList.insert(659, "SS");
    mccList.insert(702, "BZ");
    mccList.insert(704, "GT");
    mccList.insert(706, "SV");
    mccList.insert(708, "HN");
    mccList.insert(710, "NI");
    mccList.insert(712, "CR");
    mccList.insert(714, "PA");
    mccList.insert(716, "PE");
    mccList.insert(722, "AR");
    mccList.insert(724, "BR");
    mccList.insert(730, "CL");
    mccList.insert(732, "CO");
    mccList.insert(734, "VE");
    mccList.insert(736, "BO");
    mccList.insert(738, "GY");
    mccList.insert(740, "EC");
    mccList.insert(744, "PY");
    mccList.insert(746, "SR");
    mccList.insert(748, "UY");
    mccList.insert(750, "FK");


    if(mccList.contains(code))
        return mccList[code];

    return "";

}

QString normalize_phonenumber::countryPrefix(QString country) {
    QMap<QString,QString> c;
    c.insert("AF", "93");
    c.insert("AL", "355");
    c.insert("DZ", "213");
    c.insert("AS", "1-684");
    c.insert("AD", "376");
    c.insert("AO", "244");
    c.insert("AI", "1-264");
    c.insert("AQ", "672");
    c.insert("AG", "1-268");
    c.insert("AR", "54");
    c.insert("AM", "374");
    c.insert("AW", "297");
    c.insert("AU", "61");
    c.insert("AT", "43");
    c.insert("AZ", "994");
    c.insert("BS", "1-242");
    c.insert("BH", "973");
    c.insert("BD", "880");
    c.insert("BB", "1-246");
    c.insert("BY", "375");
    c.insert("BE", "32");
    c.insert("BZ", "501");
    c.insert("BJ", "229");
    c.insert("BM", "1-441");
    c.insert("BT", "975");
    c.insert("BO", "591");
    c.insert("BQ", "599");
    c.insert("BA", "387");
    c.insert("BW", "267");
    c.insert("BV", "47");
    c.insert("BR", "55");
    c.insert("IO", "246");
    c.insert("BN", "673");
    c.insert("BG", "359");
    c.insert("BF", "226");
    c.insert("BI", "257");
    c.insert("KH", "855");
    c.insert("CM", "237");
    c.insert("CA", "1");
    c.insert("CV", "238");
    c.insert("KY", "1-345");
    c.insert("CF", "236");
    c.insert("TD", "235");
    c.insert("CL", "56");
    c.insert("CN", "86");
    c.insert("CX", "61");
    c.insert("CC", "61");
    c.insert("CO", "57");
    c.insert("KM", "269");
    c.insert("CG", "242");
    c.insert("CD", "243");
    c.insert("CK", "682");
    c.insert("CR", "506");
    c.insert("HR", "385");
    c.insert("CU", "53");
    c.insert("CW", "599");
    c.insert("CY", "357");
    c.insert("CZ", "420");
    c.insert("CI", "225");
    c.insert("DK", "45");
    c.insert("DJ", "253");
    c.insert("DM", "1-767");
    c.insert("DO", "1-8091-8291-849");
    c.insert("EC", "593");
    c.insert("EG", "20");
    c.insert("SV", "503");
    c.insert("GQ", "240");
    c.insert("ER", "291");
    c.insert("EE", "372");
    c.insert("ET", "251");
    c.insert("FK", "500");
    c.insert("FO", "298");
    c.insert("FJ", "679");
    c.insert("FI", "358");
    c.insert("FR", "33");
    c.insert("GF", "594");
    c.insert("PF", "689");
    c.insert("TF", "262");
    c.insert("GA", "241");
    c.insert("GM", "220");
    c.insert("GE", "995");
    c.insert("DE", "49");
    c.insert("GH", "233");
    c.insert("GI", "350");
    c.insert("GR", "30");
    c.insert("GL", "299");
    c.insert("GD", "1-473");
    c.insert("GP", "590");
    c.insert("GU", "1-671");
    c.insert("GT", "502");
    c.insert("GG", "44");
    c.insert("GN", "224");
    c.insert("GW", "245");
    c.insert("GY", "592");
    c.insert("HT", "509");
    c.insert("HM", "672");
    c.insert("VA", "39-06");
    c.insert("HN", "504");
    c.insert("HK", "852");
    c.insert("HU", "36");
    c.insert("IS", "354");
    c.insert("IN", "91");
    c.insert("ID", "62");
    c.insert("IR", "98");
    c.insert("IQ", "964");
    c.insert("IE", "353");
    c.insert("IM", "44");
    c.insert("IL", "972");
    c.insert("IT", "39");
    c.insert("JM", "1-876");
    c.insert("JP", "81");
    c.insert("JE", "44");
    c.insert("JO", "962");
    c.insert("KZ", "7");
    c.insert("KE", "254");
    c.insert("KI", "686");
    c.insert("KP", "850");
    c.insert("KR", "82");
    c.insert("KW", "965");
    c.insert("KG", "996");
    c.insert("LA", "856");
    c.insert("LV", "371");
    c.insert("LB", "961");
    c.insert("LS", "266");
    c.insert("LR", "231");
    c.insert("LY", "218");
    c.insert("LI", "423");
    c.insert("LT", "370");
    c.insert("LU", "352");
    c.insert("MO", "853");
    c.insert("MK", "389");
    c.insert("MG", "261");
    c.insert("MW", "265");
    c.insert("MY", "60");
    c.insert("MV", "960");
    c.insert("ML", "223");
    c.insert("MT", "356");
    c.insert("MH", "692");
    c.insert("MQ", "596");
    c.insert("MR", "222");
    c.insert("MU", "230");
    c.insert("YT", "262");
    c.insert("MX", "52");
    c.insert("FM", "691");
    c.insert("MD", "373");
    c.insert("MC", "377");
    c.insert("MN", "976");
    c.insert("ME", "382");
    c.insert("MS", "1-664");
    c.insert("MA", "212");
    c.insert("MZ", "258");
    c.insert("MM", "95");
    c.insert("NA", "264");
    c.insert("NR", "674");
    c.insert("NP", "977");
    c.insert("NL", "31");
    c.insert("NC", "687");
    c.insert("NZ", "64");
    c.insert("NI", "505");
    c.insert("NE", "227");
    c.insert("NG", "234");
    c.insert("NU", "683");
    c.insert("NF", "672");
    c.insert("MP", "1-670");
    c.insert("NO", "47");
    c.insert("OM", "968");
    c.insert("PK", "92");
    c.insert("PW", "680");
    c.insert("PS", "970");
    c.insert("PA", "507");
    c.insert("PG", "675");
    c.insert("PY", "595");
    c.insert("PE", "51");
    c.insert("PH", "63");
    c.insert("PN", "870");
    c.insert("PL", "48");
    c.insert("PT", "351");
    c.insert("PR", "1");
    c.insert("QA", "974");
    c.insert("RO", "40");
    c.insert("RU", "7");
    c.insert("RW", "250");
    c.insert("RE", "262");
    c.insert("BL", "590");
    c.insert("SH", "290");
    c.insert("KN", "1-869");
    c.insert("LC", "1-758");
    c.insert("MF", "590");
    c.insert("PM", "508");
    c.insert("VC", "1-784");
    c.insert("WS", "685");
    c.insert("SM", "378");
    c.insert("ST", "239");
    c.insert("SA", "966");
    c.insert("SN", "221");
    c.insert("RS", "381");
    c.insert("SC", "248");
    c.insert("SL", "232");
    c.insert("SG", "65");
    c.insert("SX", "1-721");
    c.insert("SK", "421");
    c.insert("SI", "386");
    c.insert("SB", "677");
    c.insert("SO", "252");
    c.insert("ZA", "27");
    c.insert("GS", "500");
    c.insert("SS", "211");
    c.insert("ES", "34");
    c.insert("LK", "94");
    c.insert("SD", "249");
    c.insert("SR", "597");
    c.insert("SJ", "47");
    c.insert("SZ", "268");
    c.insert("SE", "46");
    c.insert("CH", "41");
    c.insert("SY", "963");
    c.insert("TW", "886");
    c.insert("TJ", "992");
    c.insert("TZ", "255");
    c.insert("TH", "66");
    c.insert("TL", "670");
    c.insert("TG", "228");
    c.insert("TK", "690");
    c.insert("TO", "676");
    c.insert("TT", "1-868");
    c.insert("TN", "216");
    c.insert("TR", "90");
    c.insert("TM", "993");
    c.insert("TC", "1-649");
    c.insert("TV", "688");
    c.insert("UG", "256");
    c.insert("UA", "380");
    c.insert("AE", "971");
    c.insert("GB", "44");
    c.insert("US", "1");
    c.insert("UM", "2");
    c.insert("UY", "598");
    c.insert("UZ", "998");
    c.insert("VU", "678");
    c.insert("VE", "58");
    c.insert("VN", "84");
    c.insert("VG", "1-284");
    c.insert("VI", "1-340");
    c.insert("WF", "681");
    c.insert("EH", "212");
    c.insert("YE", "967");
    c.insert("ZM", "260");
    c.insert("ZW", "263");
    c.insert("AX", "358");

    if(c.contains(country)) {
        return c[country];
    }

    return "";
}