inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����������ǵ��Ͻ֣������ǵĵ��ӡ����ˡ����������Ծ�
ס�ڳ���������Դ�������һ�����꣬����������Ǳ�ѧ��ң
֮ʿ��������֮��ͥΪ�������˼�֮��������ߴ�֮�庮������
�������ӾӴ�������Ƨ֮�أ�����������Ϣ������������������
����һ�ҵ����̣�������һ��ҩ�̡�
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
            	"south" : __DIR__"iceroad1",
            	"north" : __DIR__"iceroad3",
            	"west"  : __DIR__"wuqi",
            	"east"  : __DIR__"yaodian",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

