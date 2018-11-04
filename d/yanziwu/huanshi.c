//ROOM: /d/yanziwu/huanshi.c

inherit ROOM;
#include <ansi.h>

// �����κ�ָ�������������ָ��
#define BOOK1 "/clone/lonely/book/tianzhuzhi"
#define BOOK2 "/clone/lonely/book/duoluoyezhi"
#define BOOK3 "/clone/lonely/book/xiuluozhi"

string* books = ({ BOOK1, BOOK2, BOOK3 });

int can_creat_book = 0, ran;

void create()
{
        set("short", "��ʩˮ��");
        set("long",@LONG
�����������(jia)�� ���ϰ�������Ĺžɵ��鼮������
�����б�ǩ(sign)�������Ľ�����������������ռ����۶���
����ѧ���⡣
LONG );
        set("exits", ([
            "out": __DIR__"lanyue",
        ]));
        set("objects", ([
            "/clone/book/book-bamboo": random(2),
            "/clone/book/book-iron": random(2),
            "/clone/book/book-paper": random(2),
            "/clone/book/book-silk": random(2),
            "/clone/book/book-stone": random(2),
        ]));
        
        set("item_desc",([
            "sign" : HIR "ȱ������������񽣣�ؤ�ｵ��ʮ���ơ��򹷹�����\n" NOR,
              "jia"  : HIC "������Ÿ�����ѧ�鼮��ȴ����ûʲô�м�ֵ���ؼ���\n" NOR,
        ]));
        
        // ÿ�θ���ʱ���ѡ��һ�ֿ��Բ������ؼ������ȴ��ж� ...
        ran = random(sizeof(books));

        // ÿ�θ�����1/5�ļ��ʿ������������һ���ؼ���
        // ������ض��ؼ��ļ���Ϊ1/15�����ȴ��ж� ...
        if (random(5) == 0)can_creat_book = 1;

        setup();

}

void init()
{
        add_action("do_move", "move");      
}

int do_move(string arg)
{       
        object me, book, here;

        me = this_player();
        
        if (! arg || arg != "jia")
                 return notify_fail("��Ҫ��ʲô��\n");
     
        if (! book = find_object(books[ran]))
                  book = load_object(books[ran]);

        if (! here = find_object(__FILE__))
                  here = load_object(__FILE__);

        // ����ǰ������ȡ�ù��ؼ���ֻ�и��º�ſ��ܵڶ��β����ؼ�
        if (here->query("marks/move") || ! can_creat_book)
                  return notify_fail(HIC "������ؽ�������˿�����ʲôҲû���֡�\n" NOR);

        message_vision(HIC "$N" HIC "����ؽ�������˿���\n" NOR, me);

        if (! environment(book))
        {     
                  tell_object(me, HIY "ž~~��һ����һ��������˵��ϣ���Ͻ���������"
                              "������\n" NOR);
     
                  book->move(me);
     
                  here->set("marks/move", 1);
        }
        else return notify_fail(HIG "�����ʲô��û���֣�\n");

        return 1;
}

// ��ֻ֤��ÿ�θ��º�Ż��л�������ؼ�
void reset()
{
       object here;

       ::reset();

       if (! here = find_object(__FILE__))
                 here = load_object(__FILE__);       

       if (here->query("marks/move"))
                 here->delete("marks/move");

}

