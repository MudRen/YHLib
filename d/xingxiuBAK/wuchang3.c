inherit ROOM;

void create()
{
        set("short", "ɽ��ƽ��");
        set("long", @LONG
�����е������С��Ҳ�����޾���ɵģ����������޵ĵ�
�Ӷ������ˣ����ض��ۼ����������ľҲ�����ꡣ��������
ɢɢ�İ��˼���ľ�ˣ���Щ�ƾɡ�
LONG );
        set("exits", ([
		"east" : __DIR__"wuchang2",
        ]));
        set("outdoors", "xingxiu");
        set("for_family", "������");
        setup();
        replace_program(ROOM);
}
