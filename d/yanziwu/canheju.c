//ROOM: /d/yanziwu/canheju.c

inherit ROOM;

void create()
{
        set("short", "�κϾ�");
        set("long",@LONG
����Ľ���������������ճ����֮�أ����õû����в���
���ţ�ƽʵ��͸�Ÿ߹��ľ��������̫ʦ�Σ��Լ�ǽ�ϵ���
����͸��һ�ɷǷ�֮����
LONG  );
        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("exits", ([
            "west" : __DIR__"qiushuan",
            "east" : __DIR__"zuijing",
            "north": __DIR__"yimen",
            "south": __DIR__"shuwu",
        ]));

	set("objects", ([
		CLASS_D("murong") + "/murongbo" : 1,
	]));
        setup();
	"/clone/board/murong_b"->foo();
}
