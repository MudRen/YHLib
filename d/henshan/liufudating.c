inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
�����������쳣���塣�������з���һ�Ų輸����������
���С�ֻ���Ա�һֻ�����á������߰�Ļƽ�����ȴ����
�ڵ��ϡ������������Ƿ������򶷡�
LONG);
        set("exits", ([
                "west"   : __DIR__"liufuwest",
                "east"   : __DIR__"liufueast",
                "south"  : __DIR__"liufudayuan",
        ]));

        setup();
	replace_program(ROOM);
}
