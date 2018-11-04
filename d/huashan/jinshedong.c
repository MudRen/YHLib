// chaoyang.c

inherit ROOM;
#include <ansi.h>

#define SWORD "/clone/lonely/jinshejian"
#define BOOK "/clone/lonely/book/jinshe1"

// Modify by Rcwiz for Heros.cd

object ob;
string msg;
string look_sword();

void create()
{
        set("short", HIY "���߶�" NOR);

        msg = "ֻ������ʯ����б����һ�����ùǣ������·��������߰˳ɣ�������\n"
              "����Ȼ�пɼ����Ǹ����Ρ�������⸱���Σ�һ����������������ʯ����\n"
              "���������ɲ�������߽���ϸ�տ���ʯ�����м��ٷ��������̳ɵļ�ª\n"
              "���Σ�ÿ�����ξ�����ͬ���������㣬�������䡣�㰤�ο�ȥ�����ܲ��\n"
              "�Ķ���ͼ�Σ����²��⣬��֪������������ô���⡣ͼ�ξ�����ʯ���ϳ�\n"
              "���˼����֣�Ҳ�����������̣��չ�ȥһ�������̵���ʮ�����֣����ر�\n"
              "������������Ե����������������ĪԹ����";

        if (! ob = find_object(SWORD))
                 ob = load_object(SWORD);

        if (! environment(ob))
        {
                 destruct(ob);

                 msg += "��ʮ����֮�ԣ��и�����͹��\n��ʯ��֮�ϣ�����һ�ѽ���sword��������ʯ"
                        "�ڣ�ֱ��������\n";
        }

        else msg += "\n";

        set("long", msg);

        set("item_desc", ([
              "ya"    : NOR + WHT "�������ͱڸ��ʣ�һ�����٣�teng��ֱ�����¡�\n" NOR,
              "teng"  : HIG "һ�����٣��ڰ����ҡ���ţ�������������climb�������¡�\n" NOR,
              "sword" : (: look_sword :),
        ]));        

        setup();
}

void init()
{
        add_action("do_climb", "climb");
        add_action("do_ba", "ba");
        add_action("do_wa", "wa");
}

int do_wa()
{
        object me = this_player();
        object ob;

        if (! ob = find_object(BOOK))
                ob = load_object(BOOK);

        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ������˵�ɣ�\n");

        message_vision(HIC "$N" HIC "ʹ�����ڵ����ڣ���һ����ڳ�һ��������\n", me);

        if (environment(ob))
        {                
                me->start_busy(2);
                return 1;
        }

        tell_object(me, HIG "����Ȼ����������һ���飬�㽫������������\n");

        ob->move(me);
        me->start_busy(2);

        return 1;
}

string look_sword()
{
        object ob;
  
        if (! ob = find_object(SWORD))
                ob = load_object(SWORD);

        if (! environment(ob))
        {
              destruct(ob);
              return HIG "һ����״���صĽ���\n" NOR;
        }

        return "��Ҫ��ʲô��\n";
}

int do_ba(string arg)
{
        object me = this_player();
        object ob;
        string show;

        show = "ֻ������ʯ����б����һ�����ùǣ������·��������߰˳ɣ�������\n"
              "����Ȼ�пɼ����Ǹ����Ρ��������⸱���Σ�һ����������������ʯ����\n"
              "���������ɲ�������߽���ϸ�տ���ʯ�����м��ٷ��������̳ɵļ�ª\n"
              "���Σ�ÿ�����ξ�����ͬ���������㣬�������䡣�����ο�ȥ�����ܲ��\n"
              "�Ķ���ͼ�Σ����²��⣬��֪������������ô���⡣ͼ�ξ�����ʯ���ϳ�\n"
              "���˼����֣�Ҳ�����������̣��չ�ȥһ�������̵���ʮ�����֣����ر�\n"
              "������������Ե����������������ĪԹ����\n";

        if (! arg || arg != "sword")
               return notify_fail("��Ҫ��ʲô��\n");

        if (me->is_busy() || me->is_fighting())
               return notify_fail("����æ������˵�ɣ�\n");

        if (! ob = find_object(SWORD))
                ob = load_object(SWORD);

        me->start_busy(2);

        if (environment(ob))
                return notify_fail("��Ҫ��ʲô��\n");

        if (me->query_str() < 40)
               return notify_fail("��������㣬�޷���������\n");    

        message_vision(HIG "$N" HIG "���������ӵ��ϰγ���\n", me);
        ob->move(me);

        set("long", show);
        return 1;          
}

int do_climb(string arg)
{
        object me = this_player();

        if (me->is_busy() || me->is_fighting())
               return notify_fail("����æ������˵�ɣ�\n");

        message_vision(HIG "$N" HIG "���������������¡���\n", me);
                
        me->move("/d/huashan/chaoyang");

        me->start_busy(2);

        return 1;          
}