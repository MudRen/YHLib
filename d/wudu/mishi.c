#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ�������ʯ�ң����������ҳ��������ж���û�˴�ɨ��
�ġ�����ֻ��һ��һ����һ������Ӷ������ҷ������룬�������ұ�
�ϣ��㷢��ʯ��(wall)���ƺ���һЩ���ơ����ڹ���������ǽ����һ
����ʯ����һ������ʯ���ϰ���һ��ʯϻ(xia)��
LONG
        );
        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits", ([
                "eastup" : __DIR__"shixi",
        ]));
        set("item_desc",([
                "xia": WHT "\nһֻʯϻ�������Ǻ�ʯ������һ��ģ���"
                       "֪���Ҳ��Ҵ򿪿�����\n " NOR,
                "wall": WHT "\nǽ�Ͽ��źܶ�ӬͷС�֣�������һЩͼ����"
                       "�ƺ���һ�ż��ϳ˵���ѧ��\n " NOR,
        ]));

        set("mishi_book", 1);
        setup();
}

void init()
{
        add_action("do_think", "think");
        add_action("do_open", "open");
}

int do_open(string arg)
{
        object me, ob;
        me = this_player();

        if( !arg || arg != "xia")
                return 0;

        if( query("mishi_book") == 1 && me->query("can_learn/ǧ������") )
        {
                message_vision(HIC "$P" HIC "��ʯϻ����������һ����"
                               "�ᣬ��æȡ�˳�����\n" NOR, me);
                add("mishi_book", -1);
                ob = new(__DIR__"obj/qianzhumiji");
                ob->move(me);
        } else
                return notify_fail("\n���ʯϻ����������տ���Ҳ��\n");

        return 1;
}
int do_think(string arg)
{
        object ob;
        int c_exp, c_skill;
        ob = this_player();

        if (arg != "wall") return 0;

        c_skill = (int)ob->query_skill("qianzhu-wandushou", 1);
        c_exp = ob->query("combat_exp");

        if ( !ob->query("can_learn/ǧ������"))
        {
                message_vision(HIR "$N" HIR "��ϸ������ʯ�ڰ��죬�����޷�������������ݡ�\n" NOR, ob);
                return 1; 
        }

        if (ob->query("character") == "��������")
        {
                tell_object(ob, HIY "�����а��룺��Ϊ�˹������䣬����ѧϰ���ֺ����书��\n" NOR);
                return 1; 
        }

        if (ob->query("character") == "������")
        {
                tell_object(ob, HIY "�����а��룺�ߣ������书��Ȼ���������������𺦼���ѧ�����ã�\n" NOR);
                return 1; 
        }

        if (ob->query("jing") < 50)
        {
                message_vision(HIR "$N" HIR "����̫���ˣ��޷��ж�ʯ�ڵ����ݡ�\n" NOR, ob);
                return 1; 
        }

        if (c_skill > 119)
        {
                message_vision(WHT "$N" WHT "����ʯ������̫��ǳ�ˡ�\n" NOR, ob);
                return 1; 
        }

        if ((c_skill * c_skill * c_skill / 10) > c_exp)
        {
                message_vision(HIR "$N" HIR "��ʵս���鲻�㣬�޷�����ʯ�����ݡ�\n" NOR, ob);
                return 1; 
        }

        message_vision(HIY "$N" HIY "�����ʯ�ھ�˼���ã���ǧ��������������\n" NOR, ob);
        ob->improve_skill("qianzhu-wandushou", random(30 * ob->query("int")));
        ob->receive_damage("jing", 15);
        return 1;
}
