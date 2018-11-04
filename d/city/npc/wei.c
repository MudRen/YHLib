#include <ansi.h>
inherit NPC;

void create()
{
        set_name("Τ����", ({ "wei chunfang", "chunfang", "wei" }) );
        set("gender", "Ů��" );
        set("title", "����Ժ�ϰ���");
        set("age", 42);
        set("long", "Τ�����ǵ���¹������컨���ܶ���ΤС�����������\n"
                    "����ϣ��������̴档\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);

        set_skill("unarmed", 20);
        set_skill("force", 20);
        set_skill("dodge", 35);
        set("combat_exp", 25000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

        set("attitude", "friendly");
        set("inquiry", ([
                "name"   : "�����Ҿ���Τ������",
                "ΤС��" : "�����ҵĹԶ��ӣ����þ����㡣",
                "����Ժ" : "��������Ժ�������ݳ���ͷһ�ݵ�������ȥ����",
                "here"   : "��������Ժ�������ݳ���ͷһ�ݵ�������ȥ����",
        ]));
        setup();

        set("chat_chance", 1);
        set("chat_msg", ({
                CYN "Τ���������˵�������������ұ��µúܣ�ÿ���кü������ˡ�\n" NOR,
                CYN "Τ����ŭ������������裬Ҫ����ɲ����ë���ӵ�����Ժ����������"
                "��ɨ�����˳�ȥ��\n" NOR,
                CYN "Τ��������˵������һ˫�۾���߯�����ģ������Ǹ����\n" NOR,
        }) );
        carry_object("/d/city/obj/flower_shoe")->wear();

        carry_object("/d/city/obj/pink_cloth")->wear();
}

void init()
{
        object ob;

        ::init();

        if (! stringp(query("startroom")) ||
            find_object(query("startroom")) != environment())
                return;

        if (interactive(ob = this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
        if (! objectp(me) || environment(me) != environment())
	        return;

        command("look " + me->query("id"));

        if (me->query("gender") == "����")
        {
                command("say �㵱��������������������裬���������ɲػ�"
                        "���ӣ����ǲ���̫�࣡\n");
                command("kick " + me->query("id"));

                message("vision", HIY + me->name() + HIY "��Τ����һ����"
                        "�����⡣\n" NOR,
                        environment(me), ({me}));
                me->move("/d/city/nandajie2");

                message("vision", HIY + me->name() + HIY "���˴�����Ժ��"
                        "���˳������Ե��ڵ��ϡ�\n" NOR,
                        environment(me), ({ me }));

        } else
        {
                if (me->query("class") == "bonze")
                {
                        command("say �ϣ�" + RANK_D->query_respect(me) +
                                "Ҳ�������������Ժ����");
                        command("say �뵱���ҽӹ�һ������������ϴ�ǰһ��Ҫ��"
                                "����һ����������Ӿ͹�����������ҡ�");
                }

                if (me->query("gender") == "Ů��")
                {
                        command("say ��ѽ�������´����Ҳ��Ҥ�ӣ��ɺ���ͳ��");
                        command("sigh");
                        command("say ��ϧ�Ҽ�С�����ڣ���Ȼ�����ź��㡣");
                }
                command("say ¥��¥�µĹ����ǣ��������ˣ�");
        }
        return;
}

void unconcious()
{
        die();
}
