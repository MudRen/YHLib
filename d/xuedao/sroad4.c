inherit ROOM;

void create()
{
        set("short", "��ѩɽ��");
        set("long", @LONG
�����Ѿ����˲رߣ���ѩɽ��ɽ�ڡ���ѩɽ�ֽ��ɽ��λ
�ڴ���֮�䣬����ɽ�Ƹ߾���ɽ�����겻����ѩ�ʶ���������
�º����˼���ֻ�м�ֻͺӥ�ڸߴ�������������ããѩɽ��
LONG);
        set("exits", ([
                "eastdown"  : __DIR__"sroad3",
                "westup"    : __DIR__"sroad5",
        ]));
        set("objects", ([
                "/clone/quarry/ying" : 2,
        ]));
        set("outdoors", "xuedao");
        setup();
	replace_program(ROOM);
}
