inherit ROOM;

void create()
{
        set("short", "�����");
	set("long", @LONG
ǰ������һ��ʮ�ֶ��͵�ɽ�룬��������ֻ��Գ���̾�̨
�ϣ���˵��ǰ�ӻ�ɽˮ����������Գ�ÿ�������Ҫ����ȥ��
������Ҳ�е����ڳ�Խ���������������
LONG);
        set("exits", ([
                "northdown" : __DIR__"laojun",
                "southup"   : __DIR__"shangtianti",
        ]));
        set("objects", ([
                "/clone/quarry/hou" : 2,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "huashan" );

        setup();
        replace_program(ROOM);
}
 
