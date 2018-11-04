#include <command.h>
#include <ansi.h>
#include "tobebonze.h"

inherit NPC;
string ask_yao();
string ask_jian();

void create()
{
        set_name("����ʦ̫", ({ "jingfeng shitai","jingfeng","shitai"}));
        set("long", "����һλ����ʦ̫��ֻ����üĿ�״�����������һ�Ѹֵ���"
                    "��Ȼ��Ȼ���й����ϡ�\n");
        set("gender", "Ů��");
        set("age", 42);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "bonze");

        set("str", 21);
        set("int", 21);
        set("con", 27);
        set("dex", 24);

        set("max_qi", 1800);
        set("max_jing", 900);
        set("neili", 2400);
        set("max_neili", 2400);
        set("combat_exp", 250000);

        set_skill("force", 140);
        set_skill("emei-xinfa", 140);
        set_skill("dodge", 120);
        set_skill("zhutian-bu", 120);
        set_skill("finger", 120);
        set_skill("tiangang-zhi", 120);
        set_skill("hand", 120);
        set_skill("jieshou-jiushi", 120);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("emei-jian", 120);
        set_skill("literate", 100);
        set_skill("mahayana", 100);
        set_skill("buddhism", 100);
        set_skill("martial-cognize", 40);

        map_skill("force","emei-xinfa");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("hand", "jieshou-jiushi");
        map_skill("sword","emei-jian");
        map_skill("parry","emei-jian");

        prepare_skill("hand", "jieshou-jiushi");
        prepare_skill("finger", "tiangang-zhi");

        set("inquiry", ([
                "��ҩ" : (: ask_yao :),
                "����" : (: ask_jian :),
        ]));

        set("gao_count", 4);
        set("jian_count", 2);

        create_family("������", 4, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hand.jie" :),
                (: perform_action, "finger.ling" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        setup();
        carry_object("/d/city/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command ("say �����ӷ�ƶ�᲻�յ��ӡ�\n");
        return;
}

string ask_yao()
{
        mapping fam;
        object ob;

        if (! (fam = this_player()->query("family")) ||
           fam["family_name"] != "������")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";

        if (this_player()->query("qi") >= this_player()->query("max_qi"))
                return "��δ�����ˣ�����ҩ����ʲô��";

        if (ob = present("tianxiang gao", this_player()))
                return "�����ϲ��Ǵ��ű�����ҩ��";

        if (query("gao_count") < 1)
                return "�������ˣ�������ҩ�Ѿ������˱��ɵ��ӡ�";

        add("gao_count", -1);
        ob = new("/d/emei/obj/tianxiang-gao");
        ob->move(this_player());
        return "�������б�����ҩ������ȥ���˰ɡ�";
}

string ask_jian()
{
        mapping fam;
        object ob;

        if (! (fam = this_player()->query("family")) ||
           fam["family_name"] != "������")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";

        if (query("jian_count") < 1)
                return "������û��ʲô�����ø������´������ɡ�";

        if (ob = present("ruanjian", this_player()))
                return "�����ϲ��Ǵ�����������ô����Ҫ��";

        add("jian_count", -1);
        ob = new("/d/emei/obj/ruanjian");
        ob->move(this_player());
        return "��������һ����������ȥ�ðɡ�";
}
