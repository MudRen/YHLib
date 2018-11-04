#include <ansi.h>

inherit ROOM;

string look_zi();
int tell_player();

void create()
{
        set("short", "�ϳ���");
        set("long", @LONG
���ô˴�ֻ���±��Ͽ��ˡ��ϳ��¡����֣��Դ˶��ϣ���
ʮ�ɹ�����Ĵ�ݲ��������������ƣ�������ң������Ҳ
�����ڷ嶥ͣ�㡣ɽ��������Ԩ����Ԩ����������������
���ס����ϳ��¡�ǰ��羰���ģ�ֻ�����ʵ��̫�գ�ɽʯ��
������׵�����Ԩ�£�������ȣ���������ãã������ɽʯ
��ᾣ���ľï�ܡ���Լ�ɼ��±�������������������(zi)��̧
ͷ��һ��ɽ�����������Ǿ���֮�صľ���塣
LONG);
        set("outdoors", "jueqing");
        set("item_desc",([
                "zi" : (: look_zi :),
        ]));
        set("exits", ([
               "southdown" : __DIR__"shanlu5",
               "east"      : __DIR__"shulin2",
               "north"     : __DIR__"shanlu7",
        ]));

        set("no_clean_up", 0);

        setup();
}

void init()
{       
        add_action("do_jump", ({ "tiao", "jump" }));
}

int do_jump(string arg)
{
        object me = this_player();

        if (! arg || (arg != "ya" && arg != "down" ))
                return notify_fail("��Ҫ��ʲô��\n");

        if (me->is_busy())
                return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
                return notify_fail("�㻹���Ȱ�����ǰ����һ�������˵��\n"); 
        
        if (! me->query_temp("marks/��"))
        {
                write(HIR "�����Ҫ����" HIW "�ϳ���" HIR "�����ȷ��"
                      "��ִ��һ�θ�ָ�\n" NOR);

                me->set_temp("marks/��", 1);

                return 1;
        }

        write(HIG "\n���������������һԾ����" HIW "�ϳ���" HIG "��\n" NOR);   
        write(HIR "\n��ֻ���ö��߷�������������ʹ�������������һ���Ķ��ᵽ\n"
              "�˺����ϡ�������ǧ���·ɿ�����Ϸ�ȥ�����о��Լ�ȴԽ��\nԽ��"
              "���벻����ϳ��¾����֮�ߡ�\n" NOR);

        remove_call_out("tell_player");
        call_out("tell_player", random(6) + 6);

        return 1;
}

string look_zi()
{
        return
        HIC "\n"
        "\t��������������        ��������������\n"
        "\t��������������        ��������������\n"
        "\t����      ����        ����      ����\n"
        "\t����" NOR + HIR "��ʮ��" HIC "����        ����" NOR + HIR "  ��  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" NOR + HIR "������" HIC "����        ����" NOR + HIR "  ��  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" NOR + HIR "���ꡡ" HIC "����        ����" NOR + HIR "  ��  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" NOR + HIR "����" HIC "����        ����" NOR + HIR "  ��  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" HIR "���ڡ�" HIC "����        ����" HIR "  Ī  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" HIR "���ˡ�" HIC "����        ����" HIR "  ʧ  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" HIR "���ࡡ" HIC "����        ����" HIR "  ��  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" HIR "���ۡ�" HIC "����        ����" HIR "  Լ  " HIC "����\n"
        "\t������ �� ����        ����      ����\n" 
        "\t��������������        ��������������\n"
        "\t��������������        ��������������\n\n" NOR;
}

int tell_player()
{  
       object me = this_player();
       object ob;
     
       if (! ob = find_object(__DIR__"underya"))
               ob = load_object(__DIR__"underya");

       tell_object(me, HIY "\n��Ȼ���㿴�����澹��һ����̶���ۿ���Ҫ����̶�У�����ס\n"
                           "������ס˫Ŀ��ֻ�������ˡ�һ������ٸ�̶ˮ����̹ǣ���\n"
                           "�͵��򰶱�������ȥ�����ڴﵽ�˰��ߣ�����ʱ��ֻ����ȫ��\n"
                           "��ľ��������֪����ǰһƬģ����\n" NOR);
       me->move(ob);
       me->delete_temp("marks/��");
       me->unconcious();

       return 1;
}
