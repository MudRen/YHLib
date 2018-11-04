#include <ansi.h>
inherit NPC;

void greeting(object me);

void create()
{
        set_name("½����", ({ "lu tianshu", "lu", "tianshu"}));
        set("long", "��һ��������ü��֮�����������۷硣\n");
        set("gender", "����");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 21);

        setup();
        carry_object("/clone/cloth/cloth.c")->wear();
}

void init()
{
        object me = this_player();

        ::init();

        if (! objectp(me) || ! userp(me))
                return;

        command("hi " + me->query("id"));
        command("say ��λ" + RANK_D->query_respect(me) + "���˴�ǰȥ����"
                "�պ������һ��" HIY "��������" NOR + CYN "���ˡ�" NOR);
        command("say �������֣����ǹ��������壬�����ұ����ˡ�");
}

void check_leave(object me, string dir)
{
        if (dir == "out")
        {
                message_vision(CYN "$N" CYN "��$n" CYN "Ц����ȥ�ɣ�ȥ��"
                               "��\n" NOR, this_object(), me);
                me->set("character", "��������");
        } else
        if (dir == "west")
        {
                command("sigh");
                command("say ��ϧ����ϧ������������ܲ��ߣ�");
        }
}
