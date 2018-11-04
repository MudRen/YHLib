// Room: jianzhong ��ڣ
// Modify by Rcwiz for hero.cd
// ��������ؽ���������

#include <ansi.h>

inherit ROOM;

string look_fen();
string look_stone();
string look_sword2();
string look_sword3();

#define XUANTIE "/clone/lonely/xuantiejian"
#define NONAME "/clone/lonely/noname"

void create()
{
        set("short", "��ڣ");
        set("long",@LONG
ֻ�����ʯ�����һ����ء���أ�fen������ɽ�ȣ����������� ��
������һ��ʯ��stone�����Ͽ̣�����ڣ�����֡�վ�ڴ˴��� ɽ��̹ǣ�
��������壨lianhua���¾�ɫ׳���ޱȡ�
LONG);
        set("outdoors", "huashan");

        set("item_desc", ([
                "stone"          : (: look_stone :),
                "fen"            : (: look_fen :),
                "fir sword"      : NOR + GRN "�������������ֻ��������ƮƮ�Ļ������ԭ���Ǳ��񽣡��������µ�ʯ�̵���\n"
                                   HIM "����ʮ���ᣬ��������ľ��ʯ����Ϊ�����Դ˾��ޣ�������޽�ʤ�н�֮���� �� \n" NOR,
                "sec sword"      : (: look_sword2 :),
                "thi sword"      : (: look_sword3 :), 
                "piece"          : HIW "��������ʯƬ ����ʯƬ�µ���ʯ��Ҳ��������С�֣�\n"
                                   HIM "����ޱ������ʮ��ǰ���ã������岻�飬����֮��ȡ��� \n" NOR,
                "sec piece"      : HIW "ϸ��ʯ�̣�������С�ֵ������ؽ��޷棬���ɲ�������ʮ��ǰ��֮�������¡��� \n" NOR,
                "thi piece"      : HIW "ʯ�Ͽ�������С�֣����������ͣ��޼᲻�ݣ�����ǰ��֮���˷Ⱥ�����档�� \n" NOR,
                "big stone"      : NOR + WHT "һ��ʯͷ���ƺ��������������֮���������档\n" NOR,
                "lianhua"        : HIG "��ɫ׳���ޱȣ����Դ����jump lianhua���������塣\n" NOR,
 
        ]));

        setup();
}

void init()
{
        add_action("do_move", "move");
        add_action("do_pick", "pick");
        add_action("do_jump", "jump");
}

string look_stone()
{
        string msg;

        msg = NOR + WHT "ֻ����ʯ�ϡ���ڣ����������֮�ԣ��������������С��ʯ�̣�\n"
              HIR "����ħ������ܼ��޵�����£������˹���غ���Ⱥ�����֣�������"
              "�������౯�򣡡� \n" NOR;

        return msg;
}

string look_fen()
{
        object me = this_player();
        object ob, noname, xuantie;
        string msg;
        
        if (! ob = find_object(__FILE__));
                 ob = load_object(__FILE__);
        
        if (! ob->query_temp("moved"))
                 return NOR + WHT "�������ǽ�ħ��������񽣵ĵط�����������˴�ʯ��big stone����\n" NOR;
        
        if (! noname = find_object(NONAME));
                 noname = load_object(NONAME);

        if (! xuantie = find_object(XUANTIE));
                 xuantie = load_object(XUANTIE);
        
        // ��һ��fir sword�����񽣣��ڶ�����������������������
        if (! environment(noname) && ! environment(xuantie))
                 msg = NOR + WHT "��ڣ��¶�������ŵ�����������\n�ڵ�һ��fir sword�����ڶ���sec sword���ѽ�֮"
                       "�䣬����һ�鳤��ʯƬ��piece����\n��������ʯƬ�����һ�����ʯ֮�ϡ�\n" NOR;

        else if (! environment(noname) && environment(xuantie))
                 msg = NOR + WHT "��ڣ��¶�������ŵ������������ڵ�һ��fir sword�����ұ�"
                       "����һ�鳤��ʯƬ��piece����\n���ڶ��ѽ��Ѳ�֪ȥ��ֻ����ʯƬ��se"
                       "c piece�������̵�С�֡�\n��������ʯƬ�����һ�����ʯ֮�ϡ� \n" NOR;

        else if (environment(noname) && ! environment(xuantie))
                 msg = NOR + WHT "��ڣ��¶�������ŵ�����������\n�ڵ�һ��fir sword�����ڶ���sec sword���ѽ�֮"
                       "�䣬����һ�鳤��ʯƬ��piece����\n�������׵Ľ��Ѳ�֪ȥ��ֻ����"
                       "ʯƬ��thi piece�������̵�С�֡�\n��������ʯƬ�����һ�����ʯ֮�ϡ� \n" NOR;

        else     msg = NOR + WHT "��ڣ��¶�������ŵ�һ���������ڵ�һ��fir sword�����ұ�"
                       "����һ�鳤��ʯƬ��piece����\n��������ѽ��Ѳ�֪ȥ��ֻ����"
                       "ʯƬ��sec piece��thi piece�������̵�С�֡�\n�������ʯƬ����"
                       "�һ�����ʯ֮�ϡ� \n" NOR;

        return msg;
}

string look_sword2()
{
        object ob, xuantie;
        string msg;
        
        if (! ob = find_object(__FILE__));
                 ob = load_object(__FILE__);
        
        if (! ob->query_temp("moved"))
                 return "��Ҫ��ʲô��\n";
        
        if (! xuantie = find_object(XUANTIE));
                 xuantie = load_object(XUANTIE);

        if (environment(xuantie))
                 return "��Ҫ��ʲô��\n";

        msg = NOR + WHT "һ�Ѻ������������������һ��ʯƬ��sec piece����\n" NOR;

        if (objectp(xuantie))destruct(xuantie);
      
        return msg;
               
}

string look_sword3()
{
        object ob, noname;
        string msg;
        
        if (! ob = find_object(__FILE__));
                 ob = load_object(__FILE__);
        
        if (! ob->query_temp("moved"))
                 return "��Ҫ��ʲô��\n";
        
        if (! noname = find_object(NONAME));
                 noname = load_object(NONAME);

        if (environment(noname))
                 return "��Ҫ��ʲô��\n";

        msg = HIC "ֻ���˽���Լ�ĳߣ��������������������������һ��ʯƬ��thi piece����\n" NOR;

        if (objectp(noname))destruct(noname);
      
        return msg;
               
}

int do_move(string arg)
{
        object me = this_player();
        object ob;

        if (me->is_busy() || me->is_fighting())
              return notify_fail("��æ������˵�ɣ�\n");

        if (! arg || arg != "big stone")
              return notify_fail("��Ҫ��ʲô��\n");
        
        if (! ob = find_object(__FILE__));
                 ob = load_object(__FILE__);

        if (ob->query_temp("moved"))
                 return notify_fail("�����ʯͷ�Ѿ����ƿ��ˣ�\n");
 
                
        message_vision(HIG "$N" HIG "��������ڣ�����ʯͷһ�����ƿ� ����\n", me);

        ob->set_temp("moved", 1);
 
        me->start_busy(1);
      
        return 1;
}

int do_pick(string arg)
{
        object me = this_player();
        object ob, noname, xuantie;

        if (me->is_busy() || me->is_fighting())
              return notify_fail("��æ������˵�ɣ�\n");

        if (! arg || 
            arg != "fir sword" &&
            arg != "sec sword" &&
            arg != "thi sword")
              return notify_fail("��Ҫȡʲô��\n");
        
        if (! ob = find_object(__FILE__));
                 ob = load_object(__FILE__);

        if (! noname = find_object(NONAME));
                 noname = load_object(NONAME);

        if (! xuantie = find_object(XUANTIE));
                 xuantie = load_object(XUANTIE);

        if (! ob->query_temp("moved"))
                 return notify_fail("��Ҫ��ʲô��\n");

        switch(arg)
        {
              case "fir sword" : 
                     return notify_fail(HIC "�㽫�����������˿���������֮ͨ�������ַ��˻�ȥ��\n" NOR);

              case "sec sword":
                     if (environment(xuantie))
                           return notify_fail("����Ķ����ѱ��������ˣ�\n");

                     if (me->query("str") < 34)
                           return notify_fail("�㽫����ֻ�������ߣ�Ǻ��һ������Ȼ���ֵ���"
                                              "����ʯ��һ�������Ľ�����������һ����\n");

                     message_vision(HIM "$N" HIM "�������ؽ�����������\n" NOR, me);

                     xuantie->move(me);

                     return 1;

              case "thi sword":
                     if (environment(noname))
                           return notify_fail("����Ķ����ѱ��������ˣ�\n");
              
                     message_vision(HIM "$N" HIM "������������������\n" NOR, me);

                     noname->move(me);

                     return 1;
        }
         
        me->start_busy(1);
      
        return 1;
}

int do_jump(string arg)
{
        object me = this_player();

        if (! arg || arg != "lianhua")
             return notify_fail("��Ҫ���Ķ�����\n");

        if (me->query("qi") < 300)
             return notify_fail("���������ӡ�\n");

        if (me->is_busy() || me->is_fighting())
             return notify_fail("����æ������˵��\n");

        me->start_busy(1 + random(3));

        message_sort(HIG "\n$N" HIG "�������� ����\n" NOR, me);

       me->move(__DIR__"lianhua");
      
       return 1;
}
