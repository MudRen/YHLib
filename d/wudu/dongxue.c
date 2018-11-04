inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��Ѩ");
        set("long", @LONG
�����Ƕ��ڸߴ���һ����Ѩ���ط�С��ֻ������һ���˴�����
��ڶ�����ʲôҲ��������ֻ�ж��Ե�һ�������С�ݣ�Ҷ����˸��
�����׹⣬�Եù����쳣��
LONG );

        set("objects", ([
                  __DIR__"obj/duanchang": 1,
        ]));
    

        setup();
}

void init ()
{
        add_action("do_use", "use");
        add_action("do_fire","fire");
        add_action("do_fire","dian");
        add_action("do_insert","insert");
        add_action("do_climb","climb");
}

int do_use(string arg)
{
        object me;
        me = this_player();

        if ( !arg || arg == "" ) return 0;
        if ( !present("fire", me)) return 0;
        if ( arg == "fire" )
        {
                write( HIY "���ȼ�˻��ۣ����Ƕ�Ѩ��ʵ��̫���ˣ�һ֧����Զ��"
                       "��������Ҫ��֧��Ѳ��С�\n\n" NOR);
                return 1;
        }
}

int do_fire (string arg)
{
        object me = this_player();

        if ( !arg || arg != "huo ba" )
                return notify_fail ("�����ȼʲô��\n");

        if ( !present(arg, me))
                 return notify_fail("������û������������\n");

        message_vision (HIR "$N" HIR "���ꡱ��һ������һ֧��ѣ�\n\n" NOR, me);
        message_vision (HIY "ɲ�Ǽ����ܱ��յ����������\n" NOR, me);
        this_object()->recreate();
        me->set_temp("fire_huoba",1);
        remove_call_out ("precreate");
        call_out ("precreate",20,this_object());
        destruct(present(arg,me));
        return 1;
}

void precreate (object me)
{
        tell_room (me, WHT "���ߺ���һ�������Ϩ���ˣ������ֱ��һƬ��ڣ�\n\n" NOR);
        me->delete_temp("fire_huoba");
        me->create();
}

int do_insert (string arg)
{
        object ob;
        object me = this_player();

        if ((int)me->query_temp("fire_huoba")< 1)
             return notify_fail("���ܺ�����ģ�ʲôҲ����������\n");

        if ( !arg || arg != "tong pai")
             return notify_fail("��Ҫ����ʲô��\n");

        if ( !present(arg, me))
             return notify_fail("������û��������������\n");

        if ((int)me->query_temp("fire_huoba")< 1)
             return notify_fail("���ܺ�����ģ�ʲôҲ����������\n");

        message_vision (HIY "$N" HIY "���Ž�ͭ�Ʋ���ʯ���ϵ�С���У�\n\n" NOR,me);
        message_vision (HIC "��Ȼһ��¡¡�ľ����𶯣�$N" HIC "ֻ����һ��������ת��\n\n" NOR, me);
        destruct(present(arg,me));

        ob = load_object(__DIR__"mishi");
        ob = find_object(__DIR__"mishi");

        message("vision", HIR + me->query("name") + HIR "��Ȼ���Ҷ���϶�л��˽�����\n" NOR, ob);
        message_vision (HIR "$N" HIR "��Ȼ���ý���һ�գ���������ȥ��\n\n" NOR,me);
        me->delete_temp("fire_huoba");
        me->move(__DIR__"mishi");
        return 1;

}
int do_climb(string arg)
{
       
        object me = this_player();
        object ob;

        if( (!arg) ||!((arg == "�ұ�") || (arg == "wall")))
             return notify_fail("��Ҫ��ʲô��\n");
        message_vision(HIC "$N" HIC "С������������ұ���ͻ����ʯ��������ȥ��\n\n" NOR,me);

        ob = load_object(__DIR__"wandu3");
        ob = find_object(__DIR__"wandu3");

        message("vision", HIC + me->query("name") + HIC "���ұ�������������\n" NOR, ob);
        me->move(__DIR__"wandu3");
        return 1;
}

void recreate ()
{
        set ("short", "��Ѩ");
        set ("long", @LONG
����һ����խ�Ķ�Ѩ������ʯ��ʪ�����ģ���������̦������ϸ
�۲�һ�����ܵ���������ֶ������һ��ʯ�ڷǳ�ƽ������������
���ĺۼ������м���һ������С�ף�������Բ���(insert)ʲô��
�����ԡ�
LONG);

        setup();
}
