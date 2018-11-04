#include <ansi.h>

inherit NPC;

void greeting(object me);

void create()
{
        set_name("�ز���", ({ "dizang wang", "dizang", "wang" }));
        set("long", "����ò���ϣ�����һ���������ƹ��˼����������ɡ�\n");
        set("title", HIR "��ڤ�ظ�����֮��" NOR);
        set("nickname", HIW "��ڤ֮��" NOR);
        set("gender", "����");
        set("age", 9999);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("per", 18);
        setup();
        carry_object("/d/death/npc/obj/cloth2")->wear();
        create_family(HIR "ڤ���ز�����ǰ" NOR, 1, "��ڤ֮��");
}

void init()
{
        object me;

        ::init();
        me = this_player();
        if (! objectp(me) || ! userp(me))
                return;

        greeting(me);
}

void greeting(object me)
{
        object ob;

        if (! objectp(me) || environment(me) != environment(this_object()))
                return;

        if (! query("startroom") || base_name(environment()) != query("startroom"))
                return;

        if (undefinedp(me->query("born")))
        {
                command("say " + me->query("name") + "�����������ǳ���"
                        "ϴ�ѽ��(" NOR + HIY "wash" NOR + CYN ")��Ȼ��Ͷ"
                        "̥ȥ�ɣ�" NOR);
        } else
        {
                if (wizardp(me))
                        command("heihei " + me->query("id"));
                else
                {
                        command("kick " + me->query("id"));
                        command("say �����ܵ���������ʲô��");
                        message_vision("$Nһ�Ű�$n�ߵ���Ӱ���١�\n\n",
                                       this_object(), me);
                        me->move(VOID_OB);
                        message_vision("\n$N������ϣ�����ƨ�����۽��˼�����\n",
                                       me);
                }
        }

        if (undefinedp(me->query("born")) && ! objectp(present("miji", me)))
        {
                tell_object(me, WHT "\n�ز��������������˵�������������˲�"
                                "��������һ���ɵ�����������ȥ�����á�\n" NOR);
                command("grin");
                ob = new ("/clone/misc/newbie");
                ob->move(me, 1);
                tell_object(me, HIC "�ز�����������һ�Ž�ɫ�ĵ�ҩ���㡣\n" NOR);
                command("ke");
        }
}

int attempt_apprentice(object ob)
{
        if (! ob->query("born"))
        {
                command("say ���Ͷ̥ȥ��������Ϲ����ʲô��");
                return 0;
        }

        command("say ��������һ�߶�ȥ��");
}

