inherit ROOM;

void create()
{
        set("short", "ѩ��");
        set("long", @LONG
���Ǵ�ѩɽ���µ�һ��ѩ�ӣ��������ܹ���������ʲô��
�����������������е�ů����һЩ��
LONG);
        set("exits", ([
                "northup"   : __DIR__"sroad3",
        ]));
        set("objects", ([
                "/clone/worm/xixuezhu" : 2,
        ]));
        setup();
}

