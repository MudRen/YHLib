#include <ansi.h>

inherit ROOM;
string look_keng();
string look_desk();

#define ZHUJIAN    "/d/henshan/obj/zigai-book"

void create()
{
        set("short", "�ϸ��ɶ�");
        set("long", @LONG
��������ϸ��ɶ������������˵���������ﴦ���ϸǷ�
�£������ڻ���ѩˮ�㾭��ɽ�������ϸ��ɶ��У���������ȴ
һ��ˮҲû�У�����ȴ���������ȵ�ˮ��������ŷ���ѩˮ��
���ǻ�ֱ�����붴�У����ǴӶ�����˳��������������һ����
��ĵ��ݵش�������������ˮ�����磬���γ���ˮ������ķ�
�١����������ĵĵط���ȥ����û��·���ߣ�����Զ��������
�£�ԭ�������������һ���ͱ�֮�ϡ�ֻ����Զ������һ��ʯ
��(desk)����Ȼ������������������
LONG);
        
        set("item_desc",([
               "desk" : ( :look_desk: ),
               "keng" : ( :look_keng: ),
        ]));
        
        set("exits",([
                "north" : __DIR__"xuanya",
        ]));

        setup();

}


void init()
{       
        add_action("do_move", "move");
        add_action("do_pick", "pick");
}


int do_move(string arg)
{               
        object here;

        if (! here = find_object(__DIR__"zigaihole"))
                here = load_object(__DIR__"zigaihole");

        if (! arg || (arg != "desk" && arg != "ʯ��"))
                return notify_fail("������ʲô��\n");
       
        if (here->query_temp("marks/��"))
        {
                write(HIG "\n������һ�ƣ���ʯ���ƻ���ԭ����\n\n" NOR);
                here->delete_temp("marks/��");
                return 1;
        }
        
        
        write(HIC "\n������һ�ƣ�ʯ�����澹¶��һ����(keng)����\n\n"NOR);

        here->set_temp("marks/��", 1);
        return 1;
}

int do_pick(string arg)
{
        object here, book, me;

        me = this_player();

        if (! here = find_object(__DIR__"zigaihole"))
                here = load_object(__DIR__"zigaihole");

        if (! arg || (arg != "book"))
                return notify_fail("��Ҫ��ʲô��\n");
        
        if (here->query_temp("marks/��") || ! here->query_temp("marks/��"))
                return notify_fail("��Ҫ��ʲô��\n");

        book = find_object(ZHUJIAN);

        if (! book) book = load_object(ZHUJIAN);

        if (! environment(book))
        {
                book->move(me, 1);
                message_vision(HIC "$N" HIC "�ӿ��н�" + book->query("name") +
                               HIC "���˳�����\n" NOR, me);
                return 1;
        } else
                return notify_fail(YEL "������ʲôҲû�С�\n" NOR);
        return 1;
}

string look_desk()
{  
       object here;
        
        if (! here = find_object(__DIR__"zigaihole"))
                here = load_object(__DIR__"zigaihole");

        if (here->query_temp("marks/��"))
                return WHT "\nʯ�������ѱ����ƿ�������¶��һ����(keng)����\n";
        else
   
                return WHT "\nһ��ʯ���������Ѳ����˻ҳ���\n";

       
}

string look_keng()
{
        object here, book;

        book = find_object(ZHUJIAN);
        
        if (! here = find_object(__DIR__"zigaihole"))
                here = load_object(__DIR__"zigaihole");

        if (! here->query_temp("marks/��"))
                return "��Ҫ��ʲô��\n\n";

        if (! book) book = load_object(ZHUJIAN);

        if (environment(book))
                return HIY "\n����������ǲض����ģ�������տ���Ҳ����Ȼ����Ķ�����\n"
                           "���������ˡ�\n" NOR;

        return HIY "\nֻ���������һ��(book)�����̲�ס����(pick)��������\n" NOR;
           
}

void reset()
{
        object here;
        
        if (! here = find_object(__DIR__"zigaihole"))
                here = load_object(__DIR__"zigaihole");

        ::reset();

        here->delete_temp("marks/��");
        here->delete_temp("marks/��");

        return ;

}

