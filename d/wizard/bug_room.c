// /d/wizard/guest_room.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", HIC "BUG������" NOR);
	set("long", @LONG
��������ʦ������������bug�ĵط���Ϊ������ʦͳһ��
�����Ҳο���ʦ�����ķ����� ����ֻ�ܷ���(post)�й���
Ϸbug���⣬�Թ���ʦ��������ܷ���Ǹ�������������ӻ��⣬ 
������־����������Ȼ�����ߣ���һ��ɾ���䵵�����������
����������������Ӣ��ʥ�(help herohall) ��Ӧ�ĵط�����
����������ʦ����ҽ�����Ҳ����ͳһ�������Ч�ʣ���ҿ�
���ڴ˷����κη��ϸ���������£���ʦҲ������������ظ�֮��
��ע�⣺���������bug�뽫���±��ⶨΪ��������xxx��bug����
��ע������bug�ּӵ��ĸ�id�ϣ��뽫������bug����ϸ�������
������������ԭ�ġ����ϸ��ոø�ʽ��������һ�к����
����
                                  ==�׻�Ӣ��ʷȫ����ʦ==
LONG );

	set("exits", ([
		"west": __DIR__"guest_room",               
        ]));

	set("no_fight", 1);

	setup();
	"/clone/board/bug_b"->foo();
        replace_program(ROOM);
}

