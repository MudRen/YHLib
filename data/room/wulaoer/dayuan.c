// File(/data/room/wulaoer/dayuan.c) of wulaoer's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "��ͳǱ���Ժ");
	set ("long", @LONG
����һ��������Ժ�䣬���Ÿ�����ľ������������͸������Ͷ��
���Ӱ�ӡ�һ����·ͨ�����棬�ȵ÷ǳ�ƽ���ģ������Ǿ���������
���� 
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/suzhou/road1",
	]));

        set("outdoors", "suzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "���϶�");
        set("room_name", "��ͳǱ�");
        set("room_OWNER_id", "wulaoer");
        set("room_id", "mud");
        set("room_owner_id", "wulaoer");
        set("room_position", "��ʯ�ٵ�");
}
