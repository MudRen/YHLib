inherit ROOM;

void create()
{
        set("short", "��ɽɽ·");
        set("long", @LONG
��������ɽ��´��ɽ���ɽ�ϴ����������ɪɪ������·
����һƬ��ԭ��·��ͷ������һλ׳�����ڳ�Х���������Ͼ�
�����˺��µ����չ���.
LONG);
        set("exits", ([
            	"northup" : "/d/lingjiu/shanjiao",
            	"northdown" : __DIR__"xxh1",
            	"south" : __DIR__"tianroad1",
        ]));
        set("objects", ([
                CLASS_D("xingxiu") + "/shihou" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
                "/clone/npc/walker" : 1,
        ]));
        set("outdoors", "xingxiu");
        setup();
        replace_program(ROOM);
}

