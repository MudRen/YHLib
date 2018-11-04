#include <ansi.h>
inherit NPC;

void greeting(object me);

void create()
{
        set_name("������", ({ "hua tiegan", "hua", "tiegan"}));
        set("long", "��һ������ȥ������Ȼ��ȴ���øо��е�ʲô���ԡ�\n");
        set("gender", "����");
        set("age", 41);
        set("attitude", "peaceful");
        set("shen_type", -1);
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

        command("grin " + me->query("id"));
        command("say ��λ" + RANK_D->query_respect(me) + "������ͷ����"
                "��ʲô���˾���̫�Կ�����");
        command("say �����ң���������Ⱥ�ϸ磬�ֽ�����" HIM "���ռ�թ"
                NOR + CYN "�������˵ĵ���" NOR);
}

void check_leave(object me, string dir)
{
        if (dir == "out")
        {
                message_vision(CYN "$N" CYN "��$n" CYN "��Ц������·��"
                               "��\n" NOR, this_object(), me);
                me->set("character", "���ռ�թ");
        } else
        if (dir == "east")
        {
                command("sneer");
                command("say �ߣ�û�۹⣡");
        }
}
