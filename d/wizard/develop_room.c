// /d/wizard/guest_room.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", HIM "��Ϸ������" NOR);
	set("long", @LONG
��������ʦ����ҽ����ĵط���Ϊ������ʦͳһ������
��ֻ�ܷ���(post)������ҶԱ���Ϸ�ļ����Լ������������
����Ϸ��ĳЩ��������ʣ��Թ���ʦ�ο������ܷ���Ǹ���������
�����ӻ��⣬������־������������Ȼ�����ߣ���һ��ɾ��������
���������뵽��Ӣ��ʥ�(help herohall) ��Ӧ�ĵط�������
��������ʦ����ҽ�����Ҳ����ͳһ�������Ч�ʣ���ҿ�����
�˷����κη��ϸ���������£���ʦҲ�������ظ�֮�������ڹ���
�������Ⱥͼƻ��Թ���Ҳο�����ӭ��������
                                    ==�׻�Ӣ��ʷȫ����ʦ==
LONG );

	set("exits", ([
		"southwest": __DIR__"guest_room",               
        ]));

	set("no_fight", 1);

	setup();
	"/clone/board/develop_b"->foo();
        replace_program(ROOM);
}

