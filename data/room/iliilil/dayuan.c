
inherit PRIVATE_ROOM;

void create()
{
        set("short", "Ѫ��ħ����Ժ");
	set ("long", @LONG
����һ��������Ժ�䣬���Ÿ�����ľ������������͸������Ͷ��
���Ӱ�ӡ�һ����·ͨ�����棬�ȵ÷ǳ�ƽ���ģ������Ǿ���������
���� 
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/quanzhou/qzroad1",
	]));

        set("outdoors", "yangzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "ħ������");
        set("room_name", "Ѫ��ħ��");
        set("room_id", "xhmg");
        set("room_owner_id", "iliilil");
        set("room_position", "ɽ·");
}
