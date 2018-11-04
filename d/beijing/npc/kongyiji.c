// kongyiji.c ���Ѽ�

#include <ansi.h>

inherit NPC;

string get_yueyin();

void create()
{
        set_name("���Ѽ�", ({ "kong yiji", "kong", "yiji" }));
        set("long", "ֻ��������һ���ڱ��۾�����һ���Ҳ�\n"
                    "����ӣ����е��ա�˫�ֲ�ʱ���ô�����\n"
                    "�������̣�ҡͷ�ζ���������������ʲô\n"
                    "�ʡ��ھ����С�����Ǿ�����������ġ�");
        set("title", "��Զ�ھ��˷�����");
        set("nickname", YEL "����ϸ��" NOR);
        set("gender", "����");
        set("age", 60);
        set("shen_type", 1);
        set("class", "scholar");
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 20);
        set("dex", 20);
        set("con", 20);
        set("per", 20);

        set("combat_exp", 1000);
        set_skill("literate", 150);
        set_skill("dodge", 10);
        set_skill("unarmed", 10);

        set("inquiry", ([
                "yueyin": (: get_yueyin :),
                "����": (: get_yueyin :),
        ]) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

string get_yueyin()
{
        object me = this_player();
        int paytimes;

        if ((string)me->query("family/family_name") != "������")
        {
                return ("�㿴���Ӳ�����Զ�ھֵİɣ�����ô����ȡ�����أ�");
        }

        if (me->query("combat_exp") < 60000)
        {
                return ("�㻹�������ھ�ѧ����������˵�ɡ�");
        }

        paytimes = (int)(me->query("mud_age") / 7200);

        if (me->query("paytimes") < paytimes)
        {
                if (! (int)me->query("money_get"))
                        me->set("money_get", 500);

                if ((int)me->query("money_get") > (int)me->query("combat_exp"))
                        return ("����ȥΪ�ھ������º�������ȡ������");
           else {
                        add_money("silver", 50);
                        command("give 50 silver to " + me->query("id"));
                        me->add("money_get", 500);
                        me->add("paytimes", 1);
                        return ("�����㱾�µ��������պðɡ�");
                }
        }
        me->save();
        return ("һ���µ�ʱ�仹û������ô�������������ǲ����۸�����ʹ��ˣ�");
}
