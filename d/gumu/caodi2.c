
inherit ROOM;

void create()
{
        set("short", "�ݵ�");
        set("long", @LONG
������һƬ�ݵأ��ݺ��������û��С�ȡ��ݼ�ɢ����
һЩ�滨��΢�紵�����ҷ��˱ǡ�������ʱ���С������ˡ���
������������һЩ��ͷ���İ�ɫ���۷��ڲݵ��Ϸ���������
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "west" : __DIR__"caodi",
                "southeast" : __DIR__"hanshuitan",
        ]));
        setup();
        replace_program(ROOM);
}
