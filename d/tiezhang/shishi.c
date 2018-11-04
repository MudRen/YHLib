#include <ansi.h> 

inherit ROOM;

void create()
{
        set("short", WHT "ʯ��" NOR);
        set("long", @LONG
����һ����ɽ������ɵ�Сʯ�ݣ��м���һ��ʯ�� (shizhuo)�����ϰ�
����һյ�͵ƣ�ɢ����������ƵĹ��������ڹ��ߺܰ������ܻ�ɢ����һ��
����ù����ζ����
LONG );

        set("exits", ([
                "eastup" : __DIR__"shijie-3",
        ]));

        set("item_desc",([
                "shizhuo": WHT "\nһ��ʯ������������Ǻ�ʯ������һ��ģ��������ص�ӡ��������ӡ��\n " NOR,
                "shouyin": WHT "\nһ˫��ʯ���ϵ���ӡ����������Ű�˫��Ƕ(qian)��ȥ��\n " NOR,
        ]));

        set("mishi_book", 1);
        setup();
}

void init()
{
        add_action("do_qian", "qian");
}

int do_qian(string arg)
{
        object me, ob;
        me = this_player();

        if ( ! arg || arg != "shouyin")
                return notify_fail("��Ҫ��ʲô��\n");

        if ((int)me->query_skill("tie-zhang", 1) < 50 )
        {
                message_vision(HIY "$N" HIY "��˫��Ƕ��ʯ������ӡ�ϣ����ʲô��û�з�����\n" NOR, me);
                return 1; 
        }

        if( query("mishi_book") == 1 )
        {
                message_vision(HIR "$N" HIR "��˫��Ƕ��ʯ������ӡ�ϣ�ֻ������¡¡��һ�����죬ʯ���»�"
                               "Ȼ��һ���鼮��\n" NOR + HIC "$N" HIC "��״��ϲ����æ�������������\n"
                               NOR, me);
                add("mishi_book", -1);
                ob = new(__DIR__"obj/zhangpu");
                ob->move(me);
        } else
                return notify_fail(HIR "\n�㽫˫��Ƕ��ʯ������ӡ�ϣ�ֻ������¡¡��һ�����죬ʯ��"
                                   "�ƿ�����������ʲôҲû�С�\n" NOR);

        return 1;
}