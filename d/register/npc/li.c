#include <ansi.h>
inherit NPC;

void greeting(object me);

void create()
{
        set_name("���Գ�", ({ "li zicheng", "li", "zicheng"}));
        set("long", "����͸ɷ���������쳣������������ëë�ġ�\n");
        set("gender", "����");
        set("age", 49);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("per", 20);

        setup();
        carry_object("/clone/cloth/cloth.c")->wear();
}
void init()
{
        object me = this_player();

        ::init();

        if (! objectp(me) || ! userp(me))
                return;

        command("nod " + me->query("id"));
        command("say ��λ" + RANK_D->query_respect(me) + "�������ã�Ҫ��"
                "Ȩ�ƣ��ͱ���" HIR "�ĺ�����" NOR + CYN "���ɡ�" NOR);
        command("say ʲô������ʿ��ȫ��α���ӣ�Ҫ������ͳͳɱ�⣡");
}

void check_leave(object me, string dir)
{
        if (dir == "out")
        {
                message_vision(CYN "$N" CYN "��$n" CYN "��Ц������������"
                               "ɱ���ǰ�α���ӣ�\n" NOR, this_object(), me);
                me->set("character", "�ĺ�����");
        } else
        if (dir == "south")
        {
                command("sneer");
                command("say ��С��");
        }
}
