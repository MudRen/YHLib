inherit ROOM;

void create()
{
        object ob;
        set("short", "�ܶ�");
        set("long", @LONG
����ԭ����һ������ɽ���ϵ���Ȼ�ܶ�����Ϊ�ص����ܶ�
�Ҷ���ʮ�ָ�������ɰ�����������һ���ֿ⡣
LONG );
        set("exits", ([
            	"out" : __DIR__"xxroad5",
        ]));
        set("objects", ([
                __DIR__"obj/hulu" : 2,
                __DIR__"obj/menghan_yao" : 1 + random(2),
                __DIR__"obj/xxqingxin-san" : 1,
                __DIR__"obj/shoutao" : 1 + random(2),
                "/clone/misc/muding" : 2 + random(2),
                "/clone/book/dujing_1"  : random(2),
                
        ]));
        set("outdoors", "xingxiu");

        ob = new("/clone/misc/xiangliao");
        ob->set_amount(200 + random(100));
        ob->move(this_object());

        setup();
        replace_program(ROOM);
}
