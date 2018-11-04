#include <ansi.h>

inherit ROOM;

int tell_player();

void create()
{
        set("short", "�᷿");
        set("long", @LONG
���Ǿ���������᷿��ƽʱ���˹���������δ�������κ�
�˶��������ڡ������᷿���ü�ª�������ܳ������룬������
�¹��ϰ���һ��������ֵĻ���(pen)��
LONG);
        set("item_desc",([
               "pen" : HIC "������迴��ȥ����֣��ƺ�������ʲô���ء�\n" NOR,
        ]));

        set("exits", ([
               "east"    : __DIR__"changlang3",
        ]));

        set("no_clean_up", 0);

        setup();
}

void init()
{       
        add_action("do_turn", ({ "turn", "zhuan" }));
        add_action("do_jump", ({ "tiao", "jump" }));
}

int do_turn(string arg)
{
        object me = this_player();
        object ob;

        if (! arg || arg != "pen")
                return notify_fail("��Ҫ��ʲô��\n");

        if (! ob = find_object(__DIR__"xiangfang1"))
                ob = load_object(__DIR__"xiangfang1");

        if (me->is_busy())
                return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
                return notify_fail("�㻹���Ȱ�����ǰ����һ�������˵��\n");

        // �����Ѿ��򿪣��ٴ�ת����ر�
        if (ob->query_temp("marks/ת"))
        {
                 message_sort(HIG "\n$N�����ת�����裬һ�����Ӵ�ͷ��"
                              "����ԭ��¶���Ķ����ѱ���ȫ��ס���Ѿ�Ҳ��"
                              "���������������صİ�����\n" NOR, me);   

                 set("long",@LONG
���Ǿ���������᷿��ƽʱ���˹���������δ�������κ�
�˶��������ڡ������᷿���ü�ª�������ܳ������룬������
�¹��ϰ���һ��������ֵĻ���(pen)��
LONG);

                 ob->delete_temp("marks/ת", 1);

                 return 1; 
        }
        // ����δ�򿪣��򿪻���
        message_sort(HIY "\n$N�����ת�����裬һ�����Ӵ�ͷ����������"
                           "һ����ֻ����ͷ��¶��һ������(dong)����ԭ��"
                           "���ﾹ�����Ű�����\n" NOR, me);

       ob->set_temp("marks/ת", 1);

       set("long",@LONG
���Ǿ���������᷿��ƽʱ���˹���������δ�������κ�
�˶��������ڡ������᷿���ü�ª�������ܳ������룬��ͷ��
ȴ¶��һ����(dong)������֪��ͨ���δ��� 
LONG);

       return 1;
}

int do_jump(string arg)
{
        object me = this_player();
        object ob;

        if (! arg || (arg != "dong" && arg != "hole"))
                return notify_fail("��Ҫ��ʲô��\n");

        if (! ob = find_object(__DIR__"xiangfang1"))
                ob = load_object(__DIR__"xiangfang1");

        if (me->is_busy())
                return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
                return notify_fail("�㻹���Ȱ�����ǰ����һ�������˵��\n");
        
        if (! ob->query_temp("marks/ת"))
                return notify_fail("������ʲô��");  

        tell_room(ob, me->name() + HIW "����һԾ��������ͷ�Ķ��ڡ�\n" NOR, me);

        tell_object(me, HIC "\n������һԾ�����붴�У����ߺ����쬣��˶�����ף�����\n"
                            "��׿��飬����ֱ������ʮ����δ���ء�\n" NOR);

        remove_call_out("tell_player");
        call_out("tell_player", random(4) + 3);

        return 1;
}

int tell_player()
{
       object ob1, ob2;
       object me = this_player();
     
       // ob1 ����̶����
       if (! ob1 = find_object(__DIR__"eyutan1"))
               ob1 = load_object(__DIR__"eyutan1");

       // ob2 ����̶ˮ��
       if (! ob2 = find_object(__DIR__"eyutan2"))
               ob2 = load_object(__DIR__"eyutan2");

       tell_object(me, HIG "˼��δ������ͨһ��������ˤ��ˮ�У����¼�����\n" NOR);

       tell_room(ob1, me->name()+ HIW "\n���������£�׹��̶�С�\n" NOR, me);

       me->move(ob2);

       return 1;
}
