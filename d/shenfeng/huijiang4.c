inherit ROOM;

void create()
{
        set("short", "�չ���");
        set("long", @LONG
����һ��С�չ��꣬������������ë��̺�����ϰ�Ϊһ��
˹�ˣ�ר���չ������������һ�Ŵ���Ƥֽ�ϣ�д�����չ���
���������
LONG);
        set("exits", ([
            	"east" : __DIR__"huijiang3",
        ]));
        set("objects", ([
                __DIR__"npc/dealer": 1
	]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
