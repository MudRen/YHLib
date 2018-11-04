#include <ansi.h>
inherit NPC;

void greeting(object me);

void create()
{
        set_name("ΤС��", ({"wei xiaobao", "wei", "xiaobao"}));
        set("long", "��һ����Ƥ��������͸¶�Ž��û�а��������\n");
        set("gender", "����");
        set("age", 21);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 24);

        setup();
        carry_object("/clone/cloth/cloth.c")->wear();
}

void init()
{
        object me = this_player();

        ::init();

        if (! objectp(me) || ! userp(me))
                return;

        command("xixi " + me->query("id"));
        command("say ��λ" + RANK_D->query_respect(me) + "���٣���������"
                "���㣬�⽲�����������еġ�");
        command("say ֻ�����Һ������������" HIC "������" NOR + CYN "��"
                "�����ȥ��" NOR);
}

void check_leave(object me, string dir)
{
        if (dir == "out")
        {
                message_vision(CYN "$N" CYN "��$n" CYN "Ц�����ߣ��൷��"
                               "�ң��Ƕ�����˼��\n" NOR, this_object(), me);
                me->set("character", "������");
        } else
        if (dir == "north")
        {
                command("shake");
                command("say ���������");
        }
}
