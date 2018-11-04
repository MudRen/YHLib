// human.c

#define BASE_WEIGHT 40000

inherit F_DBASE;
inherit F_SKILL;

mapping *combat_action = ({
([      "action":               "$N��ȭ����$n��$l",
        "damage_type":  "����",
]),
([      "action":               "$N��$n��$lһץ",
        "damage_type":  "ץ��",
]),
([      "action":               "$N��$n��$l�ݺݵ�����һ��",
        "damage_type":  "����",
]),
([      "action":               "$N����ȭͷ��$n��$l��ȥ",
        "damage_type":  "����",
]),
([      "action":               "$N��׼$n��$l�����ӳ�һȭ",
        "damage_type":  "����",
]),
});

void create()
{
        seteuid(getuid());
}

void setup_human(object ob)
{
        mapping my;
        int s;
        int f, x, y;

        my = ob->query_entire_dbase();
        f = (int)ob->query_skill("force", 1);

        ob->set_default_action(__FILE__, "query_action");
        if (! stringp(my["unit"])) my["unit"] = "λ";
        if (! stringp(my["gender"])) my["gender"] = "����";
        if (undefinedp(my["can_speak"])) my["can_speak"] = 1;
        if (! stringp(my["attitude"])) my["attitude"] = "peaceful";
        if (! pointerp(my["limbs"])) my["limbs"] = ({
                "ͷ��", "����", "�ؿ�", "����", "���", "�Ҽ�", "���",
                "�ұ�", "����", "����", "����", "С��", "����", "����",
                "���", "�ҽ�"
        });

        if (undefinedp(my["age"])) my["age"] = 14;
        if (undefinedp(my["str"])) my["str"] = 10 + random(21);
        if (undefinedp(my["con"])) my["con"] = 10 + random(21);
        if (undefinedp(my["dex"])) my["dex"] = 10 + random(21);
        if (undefinedp(my["int"])) my["int"] = 10 + random(21);
        if (undefinedp(my["per"])) my["per"] = 10 + random(21);

        if (userp(ob) || undefinedp(my["max_jing"]))
        {
                s = ob->query_int();
                my["max_jing"] = 100;

                if (undefinedp(my["born"]));
                else
                if (my["age"] < 14)
                        my["max_jing"] = 50 + my["age"] * s * 2 / 3;
                else
                if (my["age"] < 24)
                        my["max_jing"] += (my["age"] - 14) * s * 2 / 3;
                else
                        my["max_jing"] += (24 - 14) * s * 2 / 3;

                if ((int)my["max_jingli"] > 0)
                        my["max_jing"] += (int)my["max_jingli"] / 4;

                // ���ǻ������������
                if (ob->query("special_skill/energy"))
                        my["max_jing"] += 50 + f * 2;

                if (my["breakup"])
                        my["max_jing"] += my["max_jing"];

                if (my["animaout"])
                        my["max_jing"] += my["max_jing"];
        }

        if (userp(ob) || undefinedp(my["max_qi"]))
        {
                s = ob->query_con() + ob->query_str();
                my["max_qi"] = 100;

                if (undefinedp(my["born"]))
                        ; else
                if (my["age"] < 14)
                        my["max_qi"] = 60 + my["age"] * my["con"] / 2;
                else
                if (my["age"] < 27)
                        my["max_qi"] += (my["age"] - 14) * s * 2 / 3;
                else
                        my["max_qi"] += (27 - 14) * s * 2 / 3;

                if ((int)my["max_neili"] > 0)
                        my["max_qi"] += (int)my["max_neili"] / 4;

                // ����Ǭ�����������Ѫ
                if (ob->query("special_skill/health"))
                        my["max_qi"] += 80 + f * 3;

                // ��������ϵ�ѧ�ķ�����
                if ((x = (int)ob->query_skill("taoism", 1)) > 39 &&
                    (y = (int)ob->query_skill("jiuyin-shengong", 1)) > 39)
                {
                        if (x > 400) x = (x - 400) / 2 + 400;
                        if (y > 400) y = (y - 400) / 2 + 400;
                        if (x > 250) x = (x - 250) / 2 + 250;
                        if (y > 250) y = (y - 250) / 2 + 250;

                        my["max_qi"] += (x + 100 ) * (y + 100) / 100;
                } else
                // ̫������ϵ�ѧ�ķ�����
                if ((x = (int)ob->query_skill("taoism", 1)) > 39 &&
                    (y = (int)ob->query_skill("taiji-shengong", 1)) > 39)
                {
                        if (x > 350) x = (x - 350) / 2 + 350;
                        if (y > 350) y = (y - 350) / 2 + 350;
                        if (x > 200) x = (x - 200) / 2 + 200;
                        if (y > 200) y = (y - 200) / 2 + 200;

                        my["max_qi"] += (x + 100 ) * (y + 100) / 100;
                } else
                // �׽�͹���ϵ�ѧ�ķ�����
                if ((x = (int)ob->query_skill("taoism", 1)) > 39 &&
                    (y = (int)ob->query_skill("yijin-duangu", 1)) > 39)
                {
                        if (x > 320) x = (x - 320) / 2 + 320;
                        if (y > 320) y = (y - 320) / 2 + 320;
                        if (x > 180) x = (x - 180) / 2 + 180;
                        if (y > 180) y = (y - 180) / 2 + 180;

                        my["max_qi"] += (x + 100 ) * (y + 100) / 100;
                } else
                // ���칦��ϵ�ѧ�ķ�����
                if ((x = (int)ob->query_skill("taoism", 1)) > 39 &&
                    (y = (int)ob->query_skill("xiantian-gong", 1)) > 39)
                {
                        if (x > 300) x = (x - 300) / 2 + 300;
                        if (y > 300) y = (y - 300) / 2 + 300;
                        if (x > 150) x = (x - 150) / 2 + 150;
                        if (y > 150) y = (y - 150) / 2 + 150;

                        my["max_qi"] += (x + 100 ) * (y + 100) / 100;
                } else
                // �̲�����ϱ̺�����������
                if ((x = (int)ob->query_skill("bihai-chaosheng", 1)) > 39 &&
                    (y = (int)ob->query_skill("bibo-shengong", 1)) > 39)
                {
                        if (x > 250) x = (x - 250) / 2 + 250;
                        if (y > 250) y = (y - 250) / 2 + 250;
                        if (x > 120) x = (x - 120) / 2 + 120;
                        if (y > 120) y = (y - 120) / 2 + 120;

                        my["max_qi"] += (x + 100 ) * (y + 100) / 100;
                }

                if (my["breakup"])
                        my["max_qi"] += my["max_qi"];
        }

        // ΪʲôҪ����0.7��������Ϊ����ֻ��Ҫ70%�ĸ��ء�
        if (! ob->query_weight())
                ob->set_weight((BASE_WEIGHT + (my["str"] - 10) * 2000) * 7 / 10);
}

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

