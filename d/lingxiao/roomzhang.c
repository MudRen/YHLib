inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG 
�߽��������������ǰ���Ǵ��СС��ҩ�ޡ�������ס��
�������ǵ�������������磬��Ϊ�˺�������԰����ڷ��ĵذ�
����������һЩϡ��ҩ������񽻸�������������˵����������
�������ã�������һЩ����ҩ�Ƹ��Ǽһ�ȡ�
LONG);
        set("exits",([
            	"north"  : __DIR__"zoulang2", 
        ]));
        set("objects", ([  
                CLASS_D("lingxiao") + "/zhangwanfeng" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

