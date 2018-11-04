#include <ansi.h>

inherit ROOM;

string look_kong();
void create()
{
        set("short", "̶��ʯ��");
        set("long", @LONG
�˴��Ǹ���Ȼ���ɵ�ʯ�ߣ������ͷ�������и�Բ����
��Ĵ��(kong)���չ�ӿ���͸�������ֻ���Ǵ�����һ��
���ɣ�ʯ����صף����ڿ��д������У��������˾���Ҳδ
��������ʯ�����չ����������˲��ٴ�����(tree)��
LONG);

         set("exits", ([
               "enter" : __DIR__"hole2",
         ]));

         set("item_desc", ([
               "kong" : (: look_kong :),
               "tree" : HIC "\n���������������������а���֮�ߡ�\n" NOR,
         ]));

         set("objects", ([
               CLASS_D("jueqing") + "/chi" : 1,
         ]));     
       
        set("no_clean_up", 0);

        setup();

}

string look_kong()
{
       string msg;
       msg = HIW "\ņͷ��ͷ��͸��Ķ�Ѩ��ȥ��ֻ���Ƕ������˵Ҳ��һ�����ɣ�"
             "�����䳤��һ��������������������ɸߣ������ʮ����������Ҳ��"
             "���˶�����˼���Σ�ʵ�������޲ߡ�\n" NOR;

      return sort_msg(msg); 
}

void init()
{       
        add_action("do_climb", ({ "climb", "pa" }));
}

int do_climb(string arg)
{
        object me = this_player();
        object ob;

        if (! arg || arg != "tree" )
                return notify_fail("��Ҫ���Ķ�����\n");

        if (! ob = find_object(__DIR__"ontree1"))
                ob = load_object(__DIR__"ontree1");

        if (me->is_busy())
                return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
                return notify_fail("�㻹���Ȱ�����ǰ����һ�������˵��\n");

        tell_room(ob, HIC + me->name() + "����������������\n" NOR, me);

        me->move(ob);

        return 1;

}


