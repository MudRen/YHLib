inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ����ĳ�������ʦ����չʾ���Ե���⿾����
���������������˴������εĲ��㼰����㡣
LONG);
        set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"chaifang",
        ]));
        set("objects", ([
                __DIR__"npc/feifei"   : 1,
                __DIR__"obj/doujiang" : 5 + random(3),
                __DIR__"obj/cake"     : 5 + random(3),
        ]));
        set("resource/water", 1);
        setup();
        replace_program(ROOM);
}
