inherit ROOM;

void create()
{
        set("short", "����԰");
        set("long",@LONG
���������������Ļ�԰����ֲ���ϵ��滨��ݣ�����Ũ
�����ʵ��ڻ������ѷ��裬�㲻�ɵĳ��ˣ��е��ֶ�������
LONG);
        set("outdoors", "yanziwu");
        set("exits", ([
                "west"  : __DIR__"changlang",
        ]));
        set("objects", ([
                "/clone/quarry/he" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
