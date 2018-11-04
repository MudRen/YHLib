#include <ansi.h>

inherit ROOM;

int out_water(object me);

void create()
{
        set("short", "����ȵ�");
        set("long", @LONG
������Ǿ���ȵף��龰һƳ֮�䣬�������ڻ��У� ����
��һ�ڴ�֮�ף� ���Ե������������족�������ڴ˴�����
��ȥ���ǰ���Ũ����Զ����һ��̶(tan)��̶������������
���� ��̶�����м����ʯ(stone)�� ����һ�����ͱ��ϴ�һ��
����(teng)�� �������Խ���������������¡�

LONG);
        set("item_desc",([
                "tan"    : HIC "��̶��ȥƽ���羵������������͸����\n" NOR,
                "stone"  : NOR + WHT "ʯͷ�а��˶�ߣ����Ʒǳ����ء�\n" NOR,
                "teng"   : NOR + YEL "������ٿ���ȥ�ܽ�ʵ����������֮�á�\n" NOR,
 
        ]));
        set("no_clean_up", 0);

        setup();
}

void init()
{       
        add_action("do_jump", ({ "tiao", "jump" }));
        add_action("do_climb", ({ "climb", "pa" }));
        add_action("do_bao", ({ "bao" }));
}

int do_bao(string arg)
{
        object me = this_player();

        if (! arg || arg != "stone")
                return notify_fail("��Ҫ��ʲô��\n");

        if (me->is_busy())
                return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
                return notify_fail("�㻹���Ȱ�����ǰ����һ�������˵��\n");     

        if (me->query_temp("marks/��"))
                return notify_fail("���Ѿ�����һ��ʯͷ�ˡ�\n"); 

        write(HIC "�㽫��ʯ���𣬶ٸ��쳣���ء�\n" NOR);
        
        // ��ʯͷ��ס�ſɳ��뺮̶��
        me->set_temp("marks/��", 1);

        return 1;
}

int do_climb(string arg)
{
        object me = this_player();
        object ob;


        if (! arg || arg != "teng")
                return notify_fail("��Ҫ��ʲô��\n");

        if (me->is_busy())
                return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
                return notify_fail("�㻹���Ȱ�����ǰ����һ�������˵��\n");
        
        write(HIG "\n����������������ȥ��\n" NOR);
        write(HIC "\n������ã���о�ƣ��֮���������ڴﵽ��ɽ�塣\n\n" NOR);

        if (! ob = find_object(__DIR__"jueqing"))
               ob = load_object(__DIR__"jueqing");

        me->move(ob);
       
        return 1;

}
int do_jump(string arg)
{
        object me = this_player();
        object ob;


        if (! arg || arg != "tan")
                return notify_fail("��Ҫ���Ķ�����\n");

        if (me->is_busy())
                return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
                return notify_fail("�㻹���Ȱ�����ǰ����һ�������˵��\n");
       
        if (me->query("tiao"))
                return 1;

        if (! me->query_temp("marks/��"))
        {                    
                write(HIW "�㳤��һ������������̶��ֱ���Ǳȥ����̶��Խ��Խ"
                      "����Ǳ\n��һ�ᣬ������ɭɭ�Ķ������������������̫ǿ"
                      "����������\n�����Σ�Ҳ������Ǳ�����ɣ�ʼ���޷����ס���\n" NOR);

                call_out("out_water", 6, me);
                me->set("tiao", 1);

                return 1;
        }
         
        // ��ס��ʯ���ܹ�Ǳ��̶��
        write(HIG "��������̶�����ڱ��д�ʯͷ�����弱�����£��͵�����ǰһ\n"
                  "����������һ����æ���������ȥ��ֻ��һ�ɼ������������\n"
                  "�ӳ��˹�ȥ������������һ���������´�ʯ���ֽ��뻮���Ƕ�\n"
                  "��ȴ��һ��бб���ϵı��ѡ���˳�ƶ��ϣ�������ʱ�� ������\n"
                  "��һ�죬Ծ����ˮ�档\n" NOR);

        if (! ob = find_object(__DIR__"underya2"))
               ob = load_object(__DIR__"underya2");

        me->move(ob);
        me->delete_temp("marks/��");
        me->delete("tiao");
       
        return 1;

}

int out_water(object me)
{      
       write(HIY "��ʱ����Ϣ���٣�ֻ�ûص����ߡ�\n" NOR);
       me->move(__DIR__"underya");
       me->delete("tiao");
       return 1;
}