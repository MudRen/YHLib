inherit ROOM;

void create()
{
        set("short", "��ׯ");
        set("long", @LONG
ׯ԰�Ĵ������ǡ���ׯ���������֡����ɫ�Ĵ��Ž�����
���ţ����澲���ĵ�һ��������û�С�
LONG);
        set("exits", ([
                "east" : __DIR__"dadao1",
        ]));
        set("objects", ([
                "/clone/quarry/gou2" : 2,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
