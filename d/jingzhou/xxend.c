inherit ROOM;

void create()
{
        set("short", "С�ﾡͷ");
        set("long", @LONG
����һ�������ֺڵ����ӣ�ɢ����һ������ˮ��ζ����ʳ
�﷢ù��ζ���������ֳ���
LONG);
        set("outdoors", "jingzhou");
        set("exits", ([
                "north" : __DIR__"xxiang",
        ]));
        set("objects", ([
                "/d/kaifeng/npc/qigai" : 2,
                "/d/beijing/npc/dipi" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
