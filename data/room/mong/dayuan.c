
inherit PRIVATE_ROOM;

void create()
{
        set("short", "Ǭ���Ӵ�Ժ");
	set ("long", @LONG
����һ��������Ժ�䣬���Ÿ�����ľ������������͸������Ͷ��
���Ӱ�ӡ�һ����·ͨ�����棬�ȵ÷ǳ�ƽ���ģ������Ǿ���������
���� 
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/wudang/wdroad1",
	]));

        set("outdoors", "yangzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "����");
        set("room_name", "Ǭ����");
        set("room_id", "qiankun");
        set("room_owner_id", "mong");
        set("room_position", "��ʯ���");
}
