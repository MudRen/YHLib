// reclaim.c

inherit F_CLEAN_UP;

int filter(object ob);

int main(object me, string arg)
{

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

		write(sprintf("Total %d objects has been cleaned.\n",
			      reclaim_objects()));
		return 1;


}
int help()
{
	write(@TEXT
ָ���ʽ: reclaim

�������еĶ��������Щ��Ӧ�����������ڴ��еĶ���
TEXT );
	return 1;
}
